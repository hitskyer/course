import pygame
class Rocket():
    def __init__(self, rocket_setting, screen):
        self.screen = screen
        self.rocket_setting = rocket_setting
        self.rocketimage = pygame.image.load("images/rocket.bmp")
        self.rocket_rect = self.rocketimage.get_rect()  # 图像矩形
        self.screen_rect = screen.get_rect()  # 屏幕矩形，左上角原点，右下角如1200,800
        self.rocket_rect.centerx = self.screen_rect.centerx  # 图像x中心，在屏幕中心
        self.rocket_rect.centery = self.screen_rect.centery  # 图像y中心，在屏幕中心
        self.centerx = float(self.rocket_rect.centerx)  # 图像x中心坐标转成浮点型，存在center中
        self.centery = float(self.rocket_rect.centery)
        self.moving_right = False
        self.moving_left = False
        self.moving_up = False
        self.moving_down = False
    def update(self):
        if self.moving_left and self.rocket_rect.left > 0:
            self.centerx -= self.rocket_setting.speed_factor
        if self.moving_right and self.rocket_rect.right < self.screen_rect.right:
            self.centerx += self.rocket_setting.speed_factor
        if self.moving_up and self.rocket_rect.top > 0:
            self.centery -= self.rocket_setting.speed_factor
        if self.moving_down and self.rocket_rect.bottom < self.screen_rect.bottom:
            self.centery += self.rocket_setting.speed_factor
        self.rocket_rect.centerx = self.centerx
        self.rocket_rect.centery = self.centery
    def blitme(self):
        self.screen.blit(self.rocketimage, self.rocket_rect)