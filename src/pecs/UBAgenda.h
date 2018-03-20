/*
 * OpenBoard
 * Authors: Elisa Aparicio Pérez (isabel.aparicio@juntaex.es)
 *          Ismael Campos Suárez (ismael.campos@juntaex.es)
 *          Rafael Jesús García Perdigón (rafael.garciap@juntaex.es)
 *          Álvaro Rubio Largo (alvaro.rubio@juntaex.es)
 *
 * Creation Date : 27/02/2018
 * Copyright (C) 2018 Junta de Extremadura.
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


#ifndef UBAGENDA_H
#define UBAGENDA_H

#include <QWidget>
#include "gui/UBDockPaletteWidget.h"
#include "UBAgendaNavigator.h"
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QLabel>

class UBAgenda : public UBDockPaletteWidget
{
    Q_OBJECT
public:
    UBAgenda(QWidget *parent = 0, const char* name="UBAgenda");
    ~UBAgenda();

    bool visibleInMode(eUBDockPaletteWidgetMode mode)
    {
        return mode == eUBDockPaletteWidget_BOARD
            || mode == eUBDockPaletteWidget_DESKTOP;
    }
    int sizeWidget();
private:
    UBAgendaNavigator* mNavigator;
    /** The layout */
    QVBoxLayout* mLayout;


signals:

public slots:
};

#endif // UBAGENDA_H
