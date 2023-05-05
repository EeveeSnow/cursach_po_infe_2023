import requests
from  pprint import pprint
from bs4 import BeautifulSoup as bs


def get_data():
    anilist_soup = bs(requests.get("https://myanimelist.net/anime/47").text, "html.parser")
    title = anilist_soup.find('div', 'h1-title').find('strong').text
    info = anilist_soup.find_all('div', 'spaceit_pad')
    for i in info:
        pprint(i.text)

get_data()