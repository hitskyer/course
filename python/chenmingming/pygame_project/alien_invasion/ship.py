import pygame
class Ship():
    def __init__(self, ai_settings, screen):
        self.screen = screen
        self.ai_settings = ai_settings
        self.image = pygame.image.load("images/ship.bmp")
        self.rect = self.image.get_rect()   #图像矩形
        self.screen_rect = screen.get_rect()    #屏幕矩形，左上角原点，右下角如1200,800
        self.rect.centerx = self.screen_rect.centerx    #图像x中心，在屏幕中心
        self.rect.bottom = self.screen_rect.bottom  #图像底边，在屏幕底边
        self.center = float(self.rect.centerx)  #图像x中心坐标转成浮点型，存在center中
        self.moving_right = False
        self.moving_left = False
    def update(self):
        if self.moving_right and self.rect.right < self.screen_rect.right:  #限制位置在屏幕内
            self.center += self.ai_settings.ship_speed_factor
        if self.moving_left and self.rect.left > 0:
            self.center -= self.ai_settings.ship_speed_factor
        self.rect.centerx = self.center
    def blitme(self):
        self.screen.blit(self.image, self.rect) #blit实现动画效果
