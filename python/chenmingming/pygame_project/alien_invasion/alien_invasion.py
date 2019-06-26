import sys
import pygame
from settings import Settings
from ship import Ship
from alien import Alien
import game_functions as gf
from pygame.sprite import Group
def run_game():
    pygame.init()
    ai_settings = Settings()    #创建游戏设置
    screen = pygame.display.set_mode((ai_settings.screen_width, ai_settings.screen_height))
    pygame.display.set_caption("Alien Invasion")    #设置标题
    ship = Ship(ai_settings, screen)    #创建游戏飞船对象
    aliens = Group()
    bullets = Group()   #创建子弹组
    gf.create_fleet(ai_settings, screen, ship, aliens)
    while True:
        gf.check_events(ai_settings, screen, ship, bullets)   #检测事件
        ship.update()   #更新ship位置
        gf.update_bullets(bullets, screen)  #更新子弹位置，删除飞出去的子弹
        # print(len(bullets))   #调试时，确认子弹飞出屏幕后被删除
        gf.update_aliens(ai_settings, aliens)
        gf.update_screen(ai_settings, screen, ship, aliens, bullets) #刷新屏幕

run_game()