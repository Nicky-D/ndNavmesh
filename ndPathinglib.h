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
#pragma once

#include <vector>

#ifndef LL_V3MATH_H
class LLVector3
{
public:
	float mV[3];
};
#endif

#ifndef LL_V4COLORU_H
class LLColor4U
{
public:
	unsigned char mV[4];
};
#endif

#ifndef LL_LLUUID_H
class LLUUID
{
public:
	unsigned char mData[16];
};
#endif

#ifndef LLQUATERNION_H
class LLQuaternion
{
public:
	double mQ[4];
};
#endif

class LLRender;

class LLPathingLib
{
public:
	enum LLPLResult
	{
		LLPL_NO_PATH,
		LLPL_PATH_GENERATED_OK,
	};

	enum LLPLCharacterType
	{
		LLPL_CHARACTER_TYPE_NONE,
		LLPL_CHARACTER_TYPE_A,
		LLPL_CHARACTER_TYPE_B,
		LLPL_CHARACTER_TYPE_C,
		LLPL_CHARACTER_TYPE_D,
	};

	enum LLShapeType
	{
		LLST_WalkableObjects = 1,
		LLST_ObstacleObjects = 2,
		LLST_MaterialPhantoms = 3,
		LLST_ExclusionPhantoms = 4,
	};

	enum LLPLRenderType
	{
		LLPL_START,
		LLPL_END,
	};

	struct Vector
	{
		double mX;
		double mY;
		double mZ;
		
		Vector& operator=( LLVector3 const &aRHS )
		{
			mX = aRHS.mV[0];
			mY = aRHS.mV[1];
			mZ = aRHS.mV[2];

			return *this;
		}
		
		operator LLVector3() const
		{
			LLVector3 ret;
			ret.mV[0] = mX;
			ret.mV[1] = mY;
			ret.mV[2] = mZ;
			return ret;
		}
	};

	struct PathingPacket
	{
		Vector mStartPointA;
		Vector mEndPointA;

		Vector mStartPointB;
		Vector mEndPointB;

		bool mHasPointA;
		bool mHasPointB;

		double mCharacterWidth;
		LLPLCharacterType mCharacterType;
	};

	struct NavMeshColor
	{
		unsigned char mR;
		unsigned char mG;
		unsigned char mB;
		unsigned char mAlpha;

		NavMeshColor& operator=( LLColor4U const &aRHS )
		{
			mR = aRHS.mV[0];
			mG = aRHS.mV[1];
			mB = aRHS.mV[2];
			mAlpha = aRHS.mV[3];

			return *this;
		}
		
	};

	struct NavMeshColors
	{
		NavMeshColor mWalkable;
		NavMeshColor mObstacle;
		NavMeshColor mMaterial;
		NavMeshColor mExclusion;
		NavMeshColor mConnectedEdge;
		NavMeshColor mBoundaryEdge;
		NavMeshColor mHeatColorBase;
		NavMeshColor mHeatColorMax;
		NavMeshColor mFaceColor;
		NavMeshColor mStarValid;
		NavMeshColor mStarInvalid;
		NavMeshColor mTestPath;
		NavMeshColor mWaterColor;
	};

	static void initSystem();
	static void quitSystem();
	static LLPathingLib* getInstance();

	bool isFunctional();

	void extractNavMeshSrcFromLLSD( std::vector< unsigned char> const &aMeshData, int aNavigation );

	LLPLResult generatePath( PathingPacket const& );
	void cleanupResidual();

	void stitchNavMeshes( );

	void renderNavMesh( void );
	void renderNavMeshShapesVBO( unsigned int aShapeTypeBitmask );
	void renderPath();
	void cleanupVBOManager();

	void renderNavMeshEdges();
	void renderPathBookend( LLRender&, LLPLRenderType );

	void setNavMeshColors( NavMeshColors const& );
	void setNavMeshMaterialType( LLPLCharacterType );

	void renderSimpleShapes( LLRender&, float );

	void createPhysicsCapsuleRep( float, float, bool, LLUUID const& );
	void cleanupPhysicsCapsuleRepResiduals();

	void processNavMeshData();
	void renderSimpleShapeCapsuleID( LLRender&, LLUUID const&, LLVector3 const&, LLQuaternion const& );
};

