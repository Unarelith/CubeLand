/*
 * =====================================================================================
 *
 *       Filename:  SceneObjectLoader.cpp
 *
 *    Description:
 *
 *        Created:  06/09/2015 18:46:44
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/Filesystem.hpp>
#include <gk/core/XMLFile.hpp>

#include "SceneObjectLoader.hpp"

#include "SpikeFactory.hpp"

void SceneObjectLoader::loadObjectsFromLevelID(gk::Scene &, u16 levelID) {
	if(gk::Filesystem::fileExists("data/config/levels/level" + std::to_string(levelID) + ".xml")) {
		gk::XMLFile doc("data/config/levels/level" + std::to_string(levelID) + ".xml");

		tinyxml2::XMLElement *objectElement = doc.FirstChildElement("level").FirstChildElement().ToElement();
		while(objectElement) {
			std::string objectName = objectElement->Name();

			// Put object loading here

			objectElement = objectElement->NextSiblingElement();
		}
	}
}

void SceneObjectLoader::loadObjectFromTile(gk::Scene &scene, u16 tileX, u16 tileY, u16 tileID) {
	switch(tileID) {
		case 2: scene.addObject(SpikeFactory::create(tileX, tileY)); break;
	}
}

