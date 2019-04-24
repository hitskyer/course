import sys
import pygame
def check_keydown_events(event, rocket):  #检测键盘按下事件
    if event.key == pygame.K_RIGHT:
        rocket.moving_right = True
    elif event.key == pygame.K_LEFT:
        rocket.moving_left = True
    elif event.key == pygame.K_UP:
        rocket.moving_up = True
    elif event.key == pygame.K_DOWN:
        rocket.moving_down = True

def check_keyup_events(event, rocket):    #检测键盘松开事件
    if event.key == pygame.K_RIGHT:
        rocket.moving_right = False
    elif event.key == pygame.K_LEFT:
        rocket.moving_left = False
    elif event.key == pygame.K_UP:
        rocket.moving_up = False
    elif event.key == pygame.K_DOWN:
        rocket.moving_down = False

def check_events(rocket):
    for event in pygame.event.get():
        if event.type == pygame.QUIT:   #退出事件
            sys.exit()
        elif event.type == pygame.KEYDOWN:  #键盘按下事件
            check_keydown_events(event, rocket)
        elif event.type == pygame.KEYUP:    #键盘松开事件
            check_keyup_events(event, rocket)

def update_screen(rocket_settings, screen, rocket):
    screen.fill(rocket_settings.bg_color)   #屏幕填充背景色
    rocket.blitme()   #rocket的动画效果
    pygame.display.flip()   #让动画尽可能流畅