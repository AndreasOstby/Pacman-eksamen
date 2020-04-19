//
// Created by Baste Angelfoss on 30/03/2020.
//

#include "Character.h"

Character::Character(Map &newMap) : map(newMap) {

}

void Character::setVelocity(int x, int y) {
    newVelocity.x = x;
    newVelocity.y = y;
}

void Character::updateVelocity() {

    velocity = newVelocity;

}

void Character::checkPelletCollision() {
    for (int x = 0; x < 2; ++x) {
        for (int y = 0; y < 2; ++y) {

            int mapX = floor(position.x / map.scl) + x;
            int mapY = floor(position.y / map.scl) + y;

            if (mapY >= map.tileset.size() || mapX >= map.tileset[mapY].size() || mapX < 0 || mapY < 0) {
                continue;
            }

            if (map.tileset[mapY][mapX] != nullptr && !map.tileset[mapY][mapX]->isDead &&
                map.tileset[mapY][mapX]->isCollision(*this, {0, 0})) {
                map.tileset[mapY][mapX]->onCollision(*this);
            }
        }
    }
}

bool Character::checkWallCollision(SDL_Point &vel) {
    for (int x = 0; x < 2 - abs(vel.x); ++x) {
        for (int y = 0; y < 2 - abs(vel.y); ++y) {

            int mapX = floor(position.x / map.scl) + vel.x * 2 + x + std::max(vel.x * -1, 0);
            int mapY = floor(position.y / map.scl) + vel.y * 2 + y + std::max(vel.y * -1, 0);
            if (mapY >= map.tileset.size() || mapX >= map.tileset[mapY].size() || mapX < 0 || mapY < 0) {
                continue;
            }

            if (map.tileset[mapY][mapX] != nullptr && !map.tileset[mapY][mapX]->isDead &&
                map.tileset[mapY][mapX]->isSolid) {
                return true;
            }
        }
    }

    return map.cage->isCollision(*this, {static_cast<double>(-vel.x), static_cast<double>(-vel.y)});
}

bool Character::stopAtIntersection(double &distanceLeft, Screen &screen) {


    if (!checkWallCollision(newVelocity)) {
        updateVelocity();
    }
    return checkWallCollision(velocity);
}

void Character::calculateMove(double &pos, int &vel, double &distanceLeft, Screen &screen) {
    double diff = std::fmod(vel * map.scl - std::fmod(pos, map.scl), map.scl);


    if (diff == 0 && stopAtIntersection(distanceLeft, screen)) {
        setVelocity(0, 0);
        updateVelocity();
        distanceLeft = 0;
    } else if (distanceLeft >= abs(diff) && diff != 0) {
        pos += diff;
        if (isAi) {
            ai();
        }
        distanceLeft -= abs(diff);
        if (position.x >= map.w*map.scl){
            position.x = -map.scl;
        }
        if (position.x < -map.scl){
            position.x = (map.w-1)*map.scl;
        }
        if (position.y >= map.h*map.scl){
            position.y = -map.scl;
        }
        if (position.y < -map.scl){
            position.y = (map.h-1)*map.scl;
        }
    } else {
        pos += distanceLeft * vel;
        distanceLeft = 0;
    }

}

void Character::move(double dt, Screen &screen) {
    if (velocity.x == 0 && velocity.y == 0) {
        updateVelocity();
        toCheckEveryStep();
        return;
    }

    double distanceLeft = speed * dt;//(dt/33)*60*speed;
    //std::cout << "x: " << newvel << "  y:" << newVelocity.y << std::endl;
    while (distanceLeft > 0) {
        if (velocity.x != 0) {
            calculateMove(position.x, velocity.x, distanceLeft, screen);
        } else if (velocity.y != 0) {
            calculateMove(position.y, velocity.y, distanceLeft, screen);
        }
        toCheckEveryStep();
    }
}

double Character::getDistance(Rect &rect, SDL_Point &offsetVel) {
    return std::sqrt(
            std::pow((position.x + offsetVel.x) - (rect.x), 2) + std::pow((position.y + offsetVel.y) - (rect.y), 2));
}

void Character::pathfind(Rect &pos) {
    double record = 1000;
    SDL_Point newNewVelocity = {0, -1};
    if (velocity.y != 1 && !checkWallCollision(newNewVelocity)) {

        double currentDistance = getDistance(pos, newNewVelocity);

        if (currentDistance < record) {
            newVelocity = newNewVelocity;
            record = currentDistance;
        }

    }
    newNewVelocity = {1, 0};
    if (velocity.x != -1 && !checkWallCollision(newNewVelocity)) {

        double currentDistance = getDistance(pos, newNewVelocity);

        if (currentDistance < record) {
            newVelocity = newNewVelocity;
            record = currentDistance;
        }

    }
    newNewVelocity = {0, 1};
    if (velocity.y != -1 && !checkWallCollision(newNewVelocity)) {

        double currentDistance = getDistance(pos, newNewVelocity);

        if (currentDistance < record) {
            newVelocity = newNewVelocity;
            record = currentDistance;
        }

    }
    newNewVelocity = {-1, 0};
    if (velocity.x != 1 && !checkWallCollision(newNewVelocity)) {

        double currentDistance = getDistance(pos, newNewVelocity);

        if (currentDistance < record) {
            newVelocity = newNewVelocity;
            record = currentDistance;
        }

    }

}

void Character::frightenGhost() {
    for (int i = 0; i < map.ghost.size(); ++i) {
        map.ghost[i]->setAiState("Frightened");
        map.ghost[i]->cooldown = 33 * 5;
        map.ghost[i]->speed = initSpeed*.9;
    }
}

void Character::setAiState(std::string newState) {
    aiState = newState;
}


