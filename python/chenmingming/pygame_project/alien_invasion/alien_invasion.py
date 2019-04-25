import sys
import pygame
from settings import Settings
from ship import Ship
import game_functions as gf
from pygame.sprite import Group
def run_game():
    pygame.init()
    ai_settings = Settings()    #创建游戏设置
    screen = pygame.display.set_mode((ai_settings.screen_width, ai_settings.screen_height))
    pygame.display.set_caption("Alien Invasion")    #设置标题
    ship = Ship(ai_settings, screen)    #创建游戏飞船对象
    bullets = Group()
    while True:
        gf.check_events(ai_settings, screen, ship, bullets)   #检测事件
        ship.update()   #更新ship位置
        bullets.update()
        for bullet in bullets.copy():
            if bullet.rect.bottom <= 0:
                bullets.remove(bullet)
        # print(len(bullets))
        gf.update_screen(ai_settings, screen, ship, bullets) #刷新屏幕

run_game()