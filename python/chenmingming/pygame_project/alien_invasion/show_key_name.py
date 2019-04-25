import pygame
import sys
def check_events(screen):
    for event in pygame.event.get():
        if event.type == pygame.QUIT:   #退出事件
            sys.exit()
        elif event.type == pygame.KEYDOWN:  #键盘按下事件
            while True:
                font = pygame.font.SysFont("宋体", 80)    #设置字体
                font_surface = font.render(str(event.key), True, (0, 0, 0), (255, 255, 255))    #渲染内容为面
                pygame.image.save(font_surface, "text.bmp") #面保存成图片
                image = pygame.image.load("text.bmp")   #获取图片
                image_rect = image.get_rect()   #获取图片的矩形
                image_rect.centerx = 200    #设置图片矩形位置
                image_rect.centery = 150
                screen.blit(image, image_rect)  #屏幕呈现该图片
                pygame.display.flip()   #屏幕刷新显示出来
                if pygame.event.poll().type == pygame.KEYUP:    #键盘松开
                    break   #退出
def run_game():
    pygame.init()
    pygame.font.init()
    screen = pygame.display.set_mode((400, 300))
    pygame.display.set_caption("测试按键......")    #设置标题
    while True:
        screen.fill((255, 255, 255))  # 屏幕填充背景色
        pygame.display.flip()   #刷新屏幕
        check_events(screen)   #检测事件

run_game()