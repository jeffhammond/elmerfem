/*****************************************************************************
 *                                                                           *
 *  Elmer, A Finite Element Software for Multiphysical Problems              *
 *                                                                           *
 *  Copyright 1st April 1995 - , CSC - IT Center for Science Ltd., Finland    *
 *                                                                           *
 *  This program is free software; you can redistribute it and/or            *
 *  modify it under the terms of the GNU General Public License              *
 *  as published by the Free Software Foundation; either version 2           *
 *  of the License, or (at your option) any later version.                   *
 *                                                                           *
 *  This program is distributed in the hope that it will be useful,          *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *  GNU General Public License for more details.                             *
 *                                                                           *
 *  You should have received a copy of the GNU General Public License        *
 *  along with this program (in file fem/GPL-2); if not, write to the        *
 *  Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,         *
 *  Boston, MA 02110-1301, USA.                                              *
 *                                                                           *
 *****************************************************************************/

/*****************************************************************************
 *                                                                           *
 *  ElmerGUI solverparameters                                                *
 *                                                                           *
 *****************************************************************************
 *                                                                           *
 *  Authors: Mikko Lyly, Juha Ruokolainen and Peter Råback                   *
 *  Email:   Juha.Ruokolainen@csc.fi                                         *
 *  Web:     http://www.csc.fi/elmer                                         *
 *  Address: CSC - IT Center for Science Ltd.                                 *
 *           Keilaranta 14                                                   *
 *           02101 Espoo, Finland                                            *
 *                                                                           *
 *  Original Date: 15 Mar 2008                                               *
 *                                                                           *
 *****************************************************************************/

#ifndef SOLVERPARAMETERS_H
#define SOLVERPARAMETERS_H

#include <QWidget>
#include <QDomDocument>
#include "dynamiceditor.h"
#include "projectio.h"
#include "ui_solverparameters.h"

class SolverParameterEditor : public QDialog
{
  Q_OBJECT

public:
  SolverParameterEditor(QWidget *parent = 0);
  ~SolverParameterEditor();

  DynamicEditor *generalOptions;
  Ui::solverParameterEditor ui;

  QString solverName;

  void appendToProject(QDomDocument*, QDomElement*);
  void readFromProject(QDomDocument*, QDomElement*);

signals:

private slots:
  void hypreStateChanged(int);
  void parasailsStateChanged(int);
  void boomerAMGStateChanged(int);
  void whatsThisButtonClicked();

private:
   ProjectIO projectIO; 

  QPushButton *whatsThisButton;
};

#endif // SOLVERPARAMETERS_H
