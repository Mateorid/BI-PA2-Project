#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <SDL2/SDL_image.h>

/**Game object types*/
enum GOType {
    PLATFORM, BALL, BLOCK, BONUS
};

/**GameObject class*/
class GameObject {
public:
    /**Destructor*/
    virtual ~GameObject();

    virtual void Init() {};

    virtual void Update() {};

    virtual void SpeedUP() {};

    virtual void SlowDown() {};

    virtual void ResetSpeed() {};

    /**
     * Uses SDL_HasIntersection to decide if 2 objects collided
     * @param object object to check collision with
     * @return true if collided false otherwise
     */
    virtual bool CollisionDetection(GameObject *object);

    virtual void Collided(bool activate) {};

    /**Renders game object*/
    virtual void Render();

    /**
     * Loads game object texture
     * @param destination of the texture
     */
    void LoadTexture(const char *destination);

    /**Acive getter*/
    bool IsActive() const { return active; }

    /**Type getter*/
    GOType GetType() const { return type; }

    /**Coord getter*/
    int GetX() const { return destR.x; }

    /**Coord getter*/
    int GetY() const { return destR.y; }

    /**Coord getter*/
    int GetH() const { return destR.h; }

    /**Coord getter*/
    int GetW() const { return destR.w; }

protected:
    /**Source & destination rectangles*/
    SDL_Rect srcR{}, destR{};
    bool active = false;
    int speed = 0;
    GOType type{};
    SDL_Texture *objTexture{};
    SDL_Renderer *objRenderer{};
};