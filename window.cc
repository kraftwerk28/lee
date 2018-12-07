//
// Created by kraftwerk28 on 07.12.18.
//

#include "window.h"

const auto _sleep = [](uint ms) -> void {
  sleep(ms);
};
using namespace sf;
using namespace std;

static auto HOVER_CL = sf::Color(100, 100, 100, 100);

void
win_thread(RenderWindow *window, RectangleShape **rects,
           bool *thread_terminated)
{

  Event evt{};
  auto hover_rect = RectangleShape(Vector2f(TILE_SIZE, TILE_SIZE));
  hover_rect.setOutlineColor(Color::White);
  hover_rect.setFillColor(Color::Transparent);
  hover_rect.setOutlineThickness(1);
  hover_rect.setPosition(Vector2f(-TILE_SIZE, -TILE_SIZE));

  int hovered_rect[2] = {-1, -1};
  bool l_click = false;
  window->setActive(true);
  while (window->isOpen())
  {
    while (window->pollEvent(evt))
    {
      switch (evt.type)
      {
        case Event::Closed:
          window->close();
          *thread_terminated = true;
          break;
        case Event::MouseMoved:
        {
          if (evt.mouseMove.x >= 0 && evt.mouseMove.y >= 0 &&
              evt.mouseMove.x < WIN_W && evt.mouseMove.y < WIN_H)
          {
            int x = evt.mouseMove.x / TILE_SIZE;
            int y = evt.mouseMove.y / TILE_SIZE;
            if (l_click)
            {
              rects[y][x].setFillColor(HOVER_CL);
            }
            hover_rect.setPosition(x * TILE_SIZE, y * TILE_SIZE);
          }

          break;
        }

        case Event::MouseButtonPressed:
          if (evt.mouseButton.button == Mouse::Button::Left)
          {
            l_click = true;
          }
          break;

        case Event::MouseButtonReleased:
          if (evt.mouseButton.button == Mouse::Button::Left)
          {
            l_click = false;
          }
          break;

        case Event::MouseLeft:
          hover_rect.setPosition(-TILE_SIZE, -TILE_SIZE);
          break;

        default:
          break;
      }
    }

    window->clear();
    for (int i = 0; i < TILE_COUNT_HOR * TILE_COUNT_VER; ++i)
    {
      window->draw(rects[i / TILE_COUNT_HOR][i % TILE_COUNT_HOR]);
    }
    window->draw(hover_rect);
    window->display();
//    _sleep(50);

  }
}

