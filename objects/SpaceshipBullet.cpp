#include "SpaceshipBullet.h"

void SpaceshipBullet::move() {
    switch (maxLines) {
        case 1: {
            bulletRect.y -= speed;
            break;
        }
        case 2: {
            switch (line) {
                case 1: {
                    bulletRect.y -= speed - speed / 5;
                    bulletRect.x -= speed / 5;
                    break;
                }
                case 2: {
                    bulletRect.y -= speed - speed / 5;
                    bulletRect.x += speed / 5;
                    break;
                }
                default: break;
            }
            break;
        }
        case 3: {
            switch (line) {
                case 1: {
                    bulletRect.y -= speed;
                    break;
                }
                case 2: {
                    bulletRect.y -= speed - speed / 4;
                    bulletRect.x -= speed / 4;
                    break;
                }
                case 3: {
                    bulletRect.y -= speed - speed / 4;
                    bulletRect.x += speed / 4;
                    break;
                }
                default: break;
            }
            break;
        }
        case 4: {
            switch (line) {
                case 1: {
                    bulletRect.y -= speed - speed / 6;
                    bulletRect.x -= speed / 6;
                    break;
                }
                case 2: {
                    bulletRect.y -= speed - speed / 6;
                    bulletRect.x += speed / 6;
                    break;
                }
                case 3: {
                    bulletRect.y -= speed - speed / 3;
                    bulletRect.x -= speed / 3;
                    break;
                }
                case 4: {
                    bulletRect.y -= speed - speed / 3;
                    bulletRect.x += speed / 3;
                    break;
                }
                default: break;
            }
            break;
        }
        case 5: {
            switch (line) {
                case 1: {
                    bulletRect.y -= speed;
                    break;
                }
                case 2: {
                    bulletRect.y -= speed - speed / 4;
                    bulletRect.x -= speed / 4;
                    break;
                }
                case 3: {
                    bulletRect.y -= speed - speed / 4;
                    bulletRect.x += speed / 4;
                    break;
                }
                case 4: {
                    bulletRect.y -= speed - speed / 2;
                    bulletRect.x -= speed / 2;
                    break;
                }
                case 5: {
                    bulletRect.y -= speed - speed / 2;
                    bulletRect.x += speed / 2;
                    break;
                }
                default: break;
            }
            break;
        }
        default: break;
    }
}
