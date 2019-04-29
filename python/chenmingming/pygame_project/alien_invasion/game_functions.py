import sys
import pygame
from bullet import Bullet
def fire_bullet(ai_settings, screen, ship, bullets):    #发射子弹
    if len(bullets) < ai_settings.bullets_allowed:  #子弹没超数量
        new_bullet = Bullet(ai_settings, screen, ship)  #生成新子弹
        bullets.add(new_bullet)     #新子弹加入组
def check_keydown_events(event,ai_settings, screen, ship, bullets):  #检测键盘按下事件
    if event.key == pygame.K_UP:
        ship.moving_up = True
    elif event.key == pygame.K_DOWN:
        ship.moving_down = True
    elif event.key == pygame.K_SPACE:   #按下空格键，发射子弹
        fire_bullet(ai_settings, screen, ship, bullets)
    elif event.key == pygame.K_q:
        sys.exit()

def check_keyup_events(event, ship):    #检测键盘松开事件
    if event.key == pygame.K_UP:
        ship.moving_up = False
    elif event.key == pygame.K_DOWN:
        ship.moving_down = False

def check_events(ai_settings, screen, ship, bullets):
    for event in pygame.event.get():
        if event.type == pygame.QUIT:   #退出事件
            sys.exit()
        elif event.type == pygame.KEYDOWN:  #键盘按下事件
            check_keydown_events(event, ai_settings, screen, ship, bullets)
        elif event.type == pygame.KEYUP:    #键盘松开事件
            check_keyup_events(event, ship)

def update_screen(ai_settings, screen, ship, alien, bullets):
    screen.fill(ai_settings.bg_color)   #屏幕填充背景色
    for bullet in bullets.sprites():    #把每个子弹画在屏幕上
        bullet.draw_bullet()
    ship.blitme()   #ship的动画效果
    alien.blitme()
    pygame.display.flip()   #刷新，让动画尽可能流畅

def update_bullets(bullets, screen):
    bullets.update()    #更新子弹位置
    for bullet in bullets.copy():   #删除飞出屏幕的子弹
        if bullet.rect.left >= screen.get_rect().right:
            bullets.remove(bullet)
