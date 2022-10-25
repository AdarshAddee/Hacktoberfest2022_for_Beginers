
from pyshorteners import Shortener

api_key="6e4862fb1fbe6c921fc199016295f932f5cb712e"

shortner= Shortener(api_key=api_key)

long_url="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.pinterest.com%2Fprior1390%2Fpokemon-images%2F&psig=AOvVaw2_xjfKW_Nvh5Ujxmqf9kR0&ust=1632317830366000&source=images&cd=vfe&ved=0CAsQjRxqFwoTCIjVm_WXkPMCFQAAAAAdAAAAABAD"

short_url=shortner.bitly.short(long_url)

print(short_url)

long_url=shortner.bitly.expand(short_url)

print("\n"+long_url)