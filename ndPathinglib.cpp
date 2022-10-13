// SPDX-License-Identifier: GPL-2.0
/**
 * Copyright (C) 2022 Nicky Dasmijn
 *
 * This program is free software; you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation; version 2.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program;
 * if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
**/

#include "ndPathinglib.h"

void LLPathingLib::initSystem()
{
}

void LLPathingLib::quitSystem()
{
}

LLPathingLib* LLPathingLib::getInstance()
{
	static LLPathingLib sObj;
	return &sObj;
}

bool LLPathingLib::isFunctional()
{
	return false;
}

void LLPathingLib::extractNavMeshSrcFromLLSD( std::vector< unsigned char > const &aMeshData, int aNavigation )
{
}

LLPathingLib::LLPLResult LLPathingLib::generatePath( PathingPacket const& )
{
	return LLPL_NO_PATH;
}

void LLPathingLib::cleanupResidual()
{
}

void LLPathingLib::stitchNavMeshes( )
{
}

void LLPathingLib::renderNavMesh( void )
{
}

void LLPathingLib::renderNavMeshShapesVBO( unsigned int aShapeTypeBitmask )
{
}

void LLPathingLib::renderPath()
{
}

void LLPathingLib::cleanupVBOManager()
{
}

void LLPathingLib::setNavMeshColors( NavMeshColors const &aColors )
{
}

void LLPathingLib::setNavMeshMaterialType( LLPLCharacterType aType )
{
}

void LLPathingLib::renderNavMeshEdges()
{
}

void LLPathingLib::renderPathBookend( LLRender&, LLPLRenderType )
{
}

void LLPathingLib::renderSimpleShapes( LLRender&, float )
{
}

void LLPathingLib::createPhysicsCapsuleRep( float, float, bool, LLUUID const& )
{
}

void LLPathingLib::cleanupPhysicsCapsuleRepResiduals()
{
}

void LLPathingLib::processNavMeshData()
{
}

void LLPathingLib::renderSimpleShapeCapsuleID( LLRender&, LLUUID const&, LLVector3 const&, LLQuaternion const& )
{
}
