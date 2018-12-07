//
// Created by kraftwerk28 on 07.12.18.
//

#ifndef LEE_WINDOW_H
#define LEE_WINDOW_H

#include <SFML/Graphics.hpp>
#include "defines.h"
#include <unistd.h>

void
win_thread(sf::RenderWindow *window, sf::RectangleShape **rects,
           bool *thread_terminated);


#endif //LEE_WINDOW_H
