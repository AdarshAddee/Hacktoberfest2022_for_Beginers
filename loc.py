import geocoder
from geopy.geocoders import Nominatim
g = geocoder.ip('me')
print(g.latlng)
# print(type(g.latlng))

from geopy.geocoders import Nominatim
 
# # initialize Nominatim API
geolocator = Nominatim(user_agent="geoapiExercises")
 
 
# # Latitude & Longitude input
Latitude = g.latlng[0]
Longitude = g.latlng[1]
print( "Your Location Is:")
 
location = geolocator.reverse(str(Latitude)+","+str(Longitude))
 
address = location.raw['address']
 
# traverse the data
city = address.get('city', '')
state = address.get('state', '')
country = address.get('country', '')
code = address.get('country_code')
zipcode = address.get('postcode')
print('City : ', city)
print('State : ', state)
print('Country : ', country)
print('Post Code : ', zipcode)