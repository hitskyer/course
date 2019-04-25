import sys
import pygame
from bullet import Bullet
def check_keydown_events(event,ai_settings, screen, ship, bullets):  #检测键盘按下事件
    if event.key == pygame.K_RIGHT:
        ship.moving_right = True
    elif event.key == pygame.K_LEFT:
        ship.moving_left = True
    elif event.key == pygame.K_SPACE:
        if len(bullets) < ai_settings.bullets_allowed:
            new_bullet = Bullet(ai_settings, screen, ship)
            bullets.add(new_bullet)

def check_keyup_events(event, ship):    #检测键盘松开事件
    if event.key == pygame.K_RIGHT:
        ship.moving_right = False
    elif event.key == pygame.K_LEFT:
        ship.moving_left = False

def check_events(ai_settings, screen, ship, bullets):
    for event in pygame.event.get():
        if event.type == pygame.QUIT:   #退出事件
            sys.exit()
        elif event.type == pygame.KEYDOWN:  #键盘按下事件
            check_keydown_events(event, ai_settings, screen, ship, bullets)

        elif event.type == pygame.KEYUP:    #键盘松开事件
            check_keyup_events(event, ship)

def update_screen(ai_settings, screen, ship, bullets):
    screen.fill(ai_settings.bg_color)   #屏幕填充背景色
    for bullet in bullets.sprites():
        bullet.draw_bullet()
    ship.blitme()   #ship的动画效果
    pygame.display.flip()   #让动画尽可能流畅