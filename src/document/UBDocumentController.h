/*
 * Copyright (C) 2015-2016 Département de l'Instruction Publique (DIP-SEM)
 *
 * Copyright (C) 2013 Open Education Foundation
 *
 * Copyright (C) 2010-2013 Groupement d'Intérêt Public pour
 * l'Education Numérique en Afrique (GIP ENA)
 *
 * This file is part of OpenBoard.
 *
 * OpenBoard is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License,
 * with a specific linking exception for the OpenSSL project's
 * "OpenSSL" library (or with modified versions of it that use the
 * same license as the "OpenSSL" library).
 *
 * OpenBoard is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenBoard. If not, see <http://www.gnu.org/licenses/>.
 */




#ifndef UBDOCUMENTCONTROLLER_H_
#define UBDOCUMENTCONTROLLER_H_

#include <QtGui>
#include <QTreeWidgetItem>
#include "document/UBDocumentContainer.h"

namespace Ui
{
    class documents;
}

#include "gui/UBMessageWindow.h"

class UBGraphicsScene;
class QDialog;
class UBDocumentProxy;
class UBBoardController;
class UBThumbnailsScene;
class UBDocumentGroupTreeItem;
class UBDocumentProxyTreeItem;
class UBMainWindow;
class UBDocumentToolsPalette;

/*Added saveDocument by rafael.garciap@juntaex.es
 * 13-Marzo-2018
 * Save Temp document to user document directory.
*/
class UBDocumentController : public UBDocumentContainer
{
    Q_OBJECT

    friend class UBDocumentTreeWidget;

    public:
        UBDocumentController(UBMainWindow* mainWindow);
        virtual ~UBDocumentController();

        void closing();
        QWidget* controlView();
        UBDocumentProxyTreeItem* findDocument(UBDocumentProxy* proxy);
        bool saveDocument(UBDocumentProxy* document);
        bool addFileToDocument(UBDocumentProxy* document);
        void deletePages(QList<QGraphicsItem*> itemsToDelete);
        int getSelectedItemIndex();

        QString documentTrashGroupName(){ return mDocumentTrashGroupName;}
        QString defaultDocumentGroupName(){ return mDefaultDocumentGroupName;}

    signals:
        void exportDone();

    public slots:
        void createNewDocument();
        void createNewDocumentGroup();
        void deleteSelectedItem();
        void renameSelectedItem();
        void openSelectedItem();
        void duplicateSelectedItem();
        void importFile();
        void moveSceneToIndex(UBDocumentProxy* proxy, int source, int target);
        void selectDocument(UBDocumentProxy* proxy, bool setAsCurrentDocument = true);
        void show();
        void hide();
        void showMessage(const QString& message, bool showSpinningWheel = false);
        void hideMessage();
        void toggleDocumentToolsPalette();
        void cut();
        void copy();
        void paste();
        void focusChanged(QWidget *old, QWidget *current);

    protected:
        virtual void setupViews();
        virtual void setupToolbar();
        void setupPalettes();
        bool isOKToOpenDocument(UBDocumentProxy* proxy);
        UBDocumentProxy* selectedDocumentProxy();
        UBDocumentProxyTreeItem* selectedDocumentProxyTreeItem();
        UBDocumentGroupTreeItem* selectedDocumentGroupTreeItem();
        QStringList allGroupNames();

        enum LastSelectedElementType
        {
            None = 0, Folder, Document, Page, Multiple
        };

        LastSelectedElementType mSelectionType;

    private:
        QWidget *mParentWidget;
        UBBoardController *mBoardController;
        Ui::documents* mDocumentUI;
        UBMainWindow* mMainWindow;
        QWidget *mDocumentWidget;
        QPointer<UBMessageWindow> mMessageWindow;
        QAction* mAddFolderOfImagesAction;
        QAction* mAddFileToDocumentAction;
        QAction* mAddImagesAction;
        bool mIsClosing;
        UBDocumentToolsPalette *mToolsPalette;
        bool mToolsPalettePositionned;
        UBDocumentGroupTreeItem* mTrashTi;
        QList<QTreeWidgetItem*> mCurrentSelection;
        QString mDocumentTrashGroupName;
        QString mDefaultDocumentGroupName;

        void selectADocumentOnTrashingSelectedOne(UBDocumentGroupTreeItem* groupTi,UBDocumentProxyTreeItem *proxyTi);
        void selectFirstDocumentInList();
        void selectATreeItemOnMultipleTrashing(bool selectNewCurrentDocument = false);
        void moveDocumentToTrash(UBDocumentGroupTreeItem* groupTi, UBDocumentProxyTreeItem *proxyTi, bool selectNewDocument);
        void moveFolderToTrash(UBDocumentGroupTreeItem* groupTi);
        void emptyTrash(bool showConfirmationDialog);
        void deleteTreeItem(QTreeWidgetItem * item, bool showConfirmationDialog, bool selectNewDocument);

        void updateCurrentSelection();
        bool multipleSelection();
        bool isDocumentInTrash(UBDocumentProxyTreeItem * document);
        bool isCurrentSelectionInTrash();
        LastSelectedElementType itemType(QTreeWidgetItem * item);

    private slots:
        void documentZoomSliderValueChanged (int value);
        void loadDocumentProxies();
        void itemSelectionChanged();
        void exportDocument();
        void itemChanged(QTreeWidgetItem * item, int column);
        void thumbnailViewResized();
        void pageSelectionChanged();
        void selectionChanged();
        void documentSceneChanged(UBDocumentProxy* proxy, int pSceneIndex);
        void pageDoubleClicked(QGraphicsItem* item, int index);
        void pageClicked(QGraphicsItem* item, int index);
        void addToDocument();
        void addDocumentInTree(UBDocumentProxy* pDocument);
        void updateDocumentInTree(UBDocumentProxy* pDocument);
        void addFolderOfImages();
        void addFileToDocument();
        void addImages();

        void refreshDocumentThumbnailsView(UBDocumentContainer* source);
};


#endif /* UBDOCUMENTCONTROLLER_H_ */
