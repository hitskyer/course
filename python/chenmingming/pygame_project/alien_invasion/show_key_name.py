import pygame
import sys
#import pygame.font
def check_events(screen):
    for event in pygame.event.get():
        if event.type == pygame.QUIT:   #退出事件
            sys.exit()
        elif event.type == pygame.KEYDOWN:  #键盘按下事件
            font = pygame.font.SysFont("monospace", 80)
            font_surface = font.render(str(event.key), True, (0, 0, 0), (255, 255, 255))
            pygame.image.save(font_surface, "text.bmp")
            image = pygame.image.load("text.bmp")
            image_rect = image.get_rect()
            screen.blit(image, image_rect)
def run_game():
    pygame.init()
    pygame.font.init()
    screen = pygame.display.set_mode((800, 600))
    pygame.display.set_caption("测试按键......")    #设置标题
    while True:
        screen.fill((255, 255, 255))  # 屏幕填充背景色
        check_events(screen)   #检测事件
        pygame.display.flip()  # 让动画尽可能流畅

run_game()