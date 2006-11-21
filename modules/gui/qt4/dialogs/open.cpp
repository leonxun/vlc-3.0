/*****************************************************************************
 * open.cpp : Advanced open dialog
 ****************************************************************************
 * Copyright (C) 2006 the VideoLAN team
 * $Id: streaminfo.cpp 16816 2006-09-23 20:56:52Z jb $
 *
 * Authors: Jean-Baptiste Kempf <jb@videolan.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA. *****************************************************************************/

#include <QTabWidget>
#include <QGridLayout>

#include "dialogs/open.hpp"
#include "components/open.hpp"

#include "qt4.hpp"
#include "util/qvlcframe.hpp"

#include "input_manager.hpp"
#include "dialogs_provider.hpp"

OpenDialog *OpenDialog::instance = NULL;

OpenDialog::OpenDialog( intf_thread_t *_p_intf ) : QVLCFrame( _p_intf )
{
    setWindowTitle( _("Open" ) );
    ui.setupUi( this );
    fileOpenPanel = new FileOpenPanel(this , _p_intf );
    diskOpenPanel = new DiskOpenPanel(this , _p_intf );
    netOpenPanel = new NetOpenPanel(this , _p_intf );
    ui.Tab->addTab(fileOpenPanel, "File");
    ui.Tab->addTab(diskOpenPanel, "Disk");
    ui.Tab->addTab(netOpenPanel, "Network");
    ui.advancedFrame->hide();

    BUTTONACT( ui.closeButton, ok());
    BUTTONACT( ui.cancelButton, cancel());
    BUTTONACT( ui.advancedButton , toggleAdvancedPanel() );
}

OpenDialog::~OpenDialog()
{
}

void OpenDialog::toggleAdvancedPanel()
{
    if (ui.advancedFrame->isVisible())
    {
        ui.advancedFrame->hide();
    }
    else
    {
        ui.advancedFrame->show();
    }
}

void OpenDialog::cancel()
{
    this->toggleVisible();
}

void OpenDialog::ok()
{
    this->toggleVisible();
}

