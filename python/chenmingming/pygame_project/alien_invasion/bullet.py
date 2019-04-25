import pygame
from pygame.sprite import Sprite

class Bullet(Sprite):
    def __init__(self, ai_settings, screen, ship):
        super().__init__()
        self.screen = screen
        self.rect = pygame.Rect(0, 0, ai_settings.bullet_width,
                                ai_settings.bullet_height)  #绘制子弹的矩形
        self.rect.centerx = ship.rect.centerx   #子弹x与飞船相同
        self.rect.top = ship.rect.top   #子弹从飞船顶部起飞
        self.y = float(self.rect.y)     #y存一份浮点的，可以精调位置
        self.color = ai_settings.bullet_color
        self.speed_factor = ai_settings.bullet_speed_factor
    def update(self):
        self.y -= self.speed_factor
        self.rect.y = self.y    #浮点y位置付给矩形图形
    def draw_bullet(self):
        pygame.draw.rect(self.screen, self.color, self.rect)    #把子弹矩形画到屏幕上