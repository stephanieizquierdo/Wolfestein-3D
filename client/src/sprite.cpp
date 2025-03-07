#include "../include/sprite.h"
#include <iostream>

Sprite::Sprite(SDL_Renderer *render, const char *rutaimg, int x, int y, int h, int w) : textura(rutaimg, render) {
    this->infoSprite.x = (x * w) + x;
    this->infoSprite.y = (y * h) + y;
    this->infoSprite.w = w;
    this->infoSprite.h = h;
    this->destino.h = h * 2;
    this->destino.w = w * 2;
}

void Sprite::renderizar(int x, int y, int angulo, SDL_Point *centro) {
    this->destino.x = x;
    this->destino.y = y;
    this->textura.renderizar(&this->infoSprite, this->destino, angulo, centro);
}

void Sprite::renderizarColumna(SDL_Rect dimension, SDL_Rect &dest) {
    dimension.x += this->infoSprite.x;
    dimension.y += this->infoSprite.y;
    dimension.h += this->infoSprite.h;
    this->textura.renderizar(&dimension, dest, 0, NULL);
}

void Sprite::reescalar(int escalarw, int escalarh) {
    this->destino.h = this->destino.h * escalarh;
    this->destino.w = this->destino.w * escalarw;
}
