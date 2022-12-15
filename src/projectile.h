#include "Tuple.h"

#ifndef RAY_TRACER_PROJECTILE_H
#define RAY_TRACER_PROJECTILE_H

class Projectile {
    private:
        Tuple _position;
        Tuple _velocity;
    public:
        Projectile(){}

        Projectile(Tuple position, Tuple velocity) {
            _position = position;
            _velocity = velocity;
        }

        void setPosition(float x, float y, float z) {
            _position = point(x, y, z);
        }

        void setVelocity(float x, float y, float z) {
            _velocity = vector(x, y, z);
        }

        Tuple getPosition() {
            return _position;
        }

        Tuple getVelocity() {
            return _velocity;
        }
};

class Environment {
    private:
        Tuple _gravity;
        Tuple _wind;

    public:
        Environment() {}

        Environment(Tuple gravity, Tuple wind) {
            _gravity = gravity;
            _wind = wind;
        }

        void setGravity(float x, float y, float z) {
            _gravity = vector(x, y, z);
        }

        void setWind(float x, float y, float z) {
            _wind = vector(x, y, z);
        }

        Tuple getGravity() {
            return _gravity;
        }

        Tuple getWind() {
            return _wind;
        }        

};

Projectile tick(Environment env, Projectile proj) {
    Tuple position = add(proj.getPosition(), proj.getVelocity());
    Tuple velocity = add(
        add(proj.getVelocity(), env.getGravity()),
        env.getWind()
    );

    return Projectile (position, velocity);
}

void fireProjectile() {
    Projectile p = Projectile(point(0, 1, 0), normalize(vector(1,1,0)));
    Environment e = Environment(vector(0, -0.1, 0), vector(-0.01, 0, 0));

    while (true) {

        p = tick(e, p);
        if (p.getPosition().getY() <= 0 ) {
            break;
        }
                
        std::cout << "( " << p.getPosition().getX() << ", " << p.getPosition().getY() << ", " << p.getPosition().getZ() << " )\n";
    }    
}

#endif