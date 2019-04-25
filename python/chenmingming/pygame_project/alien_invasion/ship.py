import pygame
class Ship():
    def __init__(self, ai_settings, screen):
        self.screen = screen
        self.ai_settings = ai_settings
        self.image = pygame.image.load("images/ship.bmp")
        self.image = pygame.transform.rotozoom(self.image, 270, 0.5)
        self.rect = self.image.get_rect()   #图像矩形
        self.screen_rect = screen.get_rect()    #屏幕矩形，左上角原点，右下角如1200,800
        self.rect.centery = self.screen_rect.centery    #图像x中心，在屏幕中心
        self.rect.left = self.screen_rect.left  #图像底边，在屏幕底边
        self.center = float(self.rect.centery)  #图像x中心坐标转成浮点型，存在center中
        self.moving_up = False
        self.moving_down = False
    def update(self):
        if self.moving_up and self.rect.top > 0:  #限制位置在屏幕内
            self.center -= self.ai_settings.ship_speed_factor
        if self.moving_down and self.rect.bottom < self.screen_rect.bottom:
            self.center += self.ai_settings.ship_speed_factor
        self.rect.centery = self.center
    def blitme(self):
        self.screen.blit(self.image, self.rect) #blit实现动画效果
