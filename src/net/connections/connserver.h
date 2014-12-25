/*
 * This file is part of the Colobot: Gold Edition source code
 * Copyright (C) 2001-2014, Daniel Roux, EPSITEC SA & TerranovaTeam
 * http://epsiteс.ch; http://colobot.info; http://github.com/colobot
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://gnu.org/licenses
 */

#pragma once

#include "net/connections/conn.h"

#include <boost/asio.hpp>

class CServer;

class CServerConnection : public CConnection
{
public:
    CServerConnection(boost::asio::io_service& service, CServer* server);

    void Start();
    void Receive(PacketType packet, std::string data = "");

private:
    void PacketConnect(std::string data);
    void PacketObjectUpdate(std::string data);
    void PacketDisconnect(std::string data);
    
    CServer* m_server;
    std::string m_playerName;
};
