class Settings():
    def __init__(self):
        self.screen_width = 1200
        self.screen_height = 800
        self.bg_color = (255, 255, 255)
        self.ship_speed_factor = 1.5    #飞船速度
        self.bullet_speed_factor = 1    #子弹速度
        self.bullet_width = 30           #子弹宽高
        self.bullet_height = 10
        self.bullet_color = 60, 60, 100  #子弹颜色
        self.bullets_allowed = 3        #屏幕中允许的子弹数量