import pygame
from pygame.sprite import Sprite

class Bullet(Sprite):
    def __init__(self, ai_settings, screen, ship):
        super().__init__()
        self.screen = screen
        self.rect = pygame.Rect(0, 0, ai_settings.bullet_width,
                                ai_settings.bullet_height)  #绘制子弹的矩形
        self.rect.centery = ship.rect.centery   #子弹y与飞船相同
        self.rect.right = ship.rect.right   #子弹从飞船右部起飞
        self.x = float(self.rect.x)     # x存一份浮点的，可以精调位置
        self.color = ai_settings.bullet_color   #子弹颜色
        self.speed_factor = ai_settings.bullet_speed_factor #子弹速度
    def update(self):
        self.x += self.speed_factor #位置更新
        self.rect.x = self.x    #浮点y位置付给矩形图形
    def draw_bullet(self):
        pygame.draw.rect(self.screen, self.color, self.rect)    #把子弹矩形画到屏幕上