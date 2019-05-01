from pygal_maps_world.i18n import COUNTRIES
def get_country_code(country_name):
    for code, name in COUNTRIES.items():
        if name == country_name:
            return code #从库里返回2个字母的国家编码
    return None