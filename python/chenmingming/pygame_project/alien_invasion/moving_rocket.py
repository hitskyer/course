import sys
import pygame
from rocket_settings import RocketSettings
from rocket import Rocket
import rocket_functions as rf
def go_rocket():
    pygame.init()
    game_setting = RocketSettings()
    screen = pygame.display.set_mode((game_setting.screen_width, game_setting.screen_height))
    pygame.display.set_caption("测试小火箭")
    rocket = Rocket(game_setting, screen)
    while True:
        rf.check_events(rocket)
        rocket.update()
        rf.update_screen(game_setting, screen, rocket)
go_rocket()