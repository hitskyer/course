import sys
import pygame
from settings import Settings
from ship import Ship
import game_functions as gf
def run_game():
    pygame.init()
    ai_settings = Settings()    #创建游戏设置
    screen = pygame.display.set_mode((ai_settings.screen_width, ai_settings.screen_height))
    pygame.display.set_caption("Alien Invasion")    #设置标题
    ship = Ship(ai_settings, screen)    #创建游戏对象
    while True:
        gf.check_events(ship)   #检测事件
        ship.update()   #更新ship位置
        gf.update_screen(ai_settings, screen, ship) #刷新屏幕

run_game()