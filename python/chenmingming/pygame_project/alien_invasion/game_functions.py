import sys
import pygame
def check_keydown_events(event, ship):  #检测键盘按下事件
    if event.key == pygame.K_RIGHT:
        ship.moving_right = True
    elif event.key == pygame.K_LEFT:
        ship.moving_left = True

def check_keyup_events(event, ship):    #检测键盘松开事件
    if event.key == pygame.K_RIGHT:
        ship.moving_right = False
    elif event.key == pygame.K_LEFT:
        ship.moving_left = False

def check_events(ship):
    for event in pygame.event.get():
        if event.type == pygame.QUIT:   #退出事件
            sys.exit()
        elif event.type == pygame.KEYDOWN:  #键盘按下事件
            check_keydown_events(event, ship)
        elif event.type == pygame.KEYUP:    #键盘松开事件
            check_keyup_events(event, ship)

def update_screen(ai_settings, screen, ship):
    screen.fill(ai_settings.bg_color)   #屏幕填充背景色
    ship.blitme()   #ship的动画效果
    pygame.display.flip()   #让动画尽可能流畅