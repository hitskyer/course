import sys
import pygame
from bullet import Bullet
from alien import Alien
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

def update_screen(ai_settings, screen, ship, aliens, bullets):
    screen.fill(ai_settings.bg_color)   #屏幕填充背景色
    for bullet in bullets.sprites():    #把每个子弹画在屏幕上
        bullet.draw_bullet()
    ship.blitme()   #ship的动画效果
    aliens.draw(screen)
    pygame.display.flip()   #刷新，让动画尽可能流畅

def update_bullets(bullets, screen):
    bullets.update()    #更新子弹位置
    for bullet in bullets.copy():   #删除飞出屏幕的子弹
        if bullet.rect.left >= screen.get_rect().right:
            bullets.remove(bullet)
def update_aliens(ai_settings, aliens):
    check_fleet_edges(ai_settings, aliens)
    aliens.update()
def create_fleet(ai_settings, screen, ship, aliens):
    alien = Alien(ai_settings, screen)
    number_aliens_y = get_number_aliens_y(ai_settings, alien.rect.height)
    number_rows = get_number_rows(ai_settings, ship.rect.width, alien.rect.width)
    for row_number in range(number_rows):
        for alien_number in range(number_aliens_y):
            create_alien(ai_settings, screen, aliens, alien_number, row_number)
def check_fleet_edges(ai_settings, aliens):
    for alien in aliens.sprites():
        if alien.check_edges():
            change_fleet_direction(ai_settings, aliens)
            break
def change_fleet_direction(ai_settings, aliens):
    for alien in aliens.sprites():
        alien.rect.x -= ai_settings.fleet_drop_speed
    ai_settings.fleet_direction *= -1
def get_number_aliens_y(ai_settings, alien_height):
    available_space_y = ai_settings.screen_height - 2 * alien_height
    number_alien_y = int(available_space_y / (2 * alien_height))
    return number_alien_y
def create_alien(ai_settings, screen, aliens, alien_number, row_number):
    alien = Alien(ai_settings, screen)
    alien_height = alien.rect.height
    alien.y = alien_height + 2 * alien_height * alien_number
    alien.rect.y = alien.y
    alien.rect.x = ai_settings.screen_width - 2 * alien.rect.width * row_number
    aliens.add(alien)
def get_number_rows(ai_settings, ship_width, alien_width):
    available_apace_x = (ai_settings.screen_width - (3 * alien_width) - ship_width)
    number_rows = int(available_apace_x / (2 * alien_width))
    return number_rows