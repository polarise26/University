import time
import requests
import pandas as pd

from selenium import webdriver
from lib2to3.pgen2 import driver
from bs4 import BeautifulSoup

years = list(range(1991, 2022))
url_start = "https://www.basketball-reference.com/awards/awards_{}.html"

for year in years:
    URL = url_start.format(year)

    data = requests.get(URL)

    with open("year-2\\sem-4\\ML\\extras\\project-2\\Proto\\mvp\\{}.html".format(year), "w+", encoding="utf-8") as f:
        f.write(data.text)

# Creating a list of MVP Voting dataframes, by going to the table with id = "mvp", scraping the data and then saving it in a list.

mvpDFs = []
for year in years:
    with open("year-2\\sem-4\\ML\\extras\\project-2\\Proto\\mvp\\{}.html".format(year), encoding="utf-8") as f:
        page = f.read()

    soup = BeautifulSoup(page, 'html.parser')
    soup.find('tr', class_="over_header").decompose()
    mvpTable = soup.find_all(id="mvp")[0]
    mvpDF = pd.read_html(str(mvpTable))[0]
    mvpDF["Year"] = year
    mvpDFs.append(mvpDF)

mvps = pd.concat(mvpDFs)
print(mvps)
mvps.to_csv("year-2\\sem-4\\ML\\extras\\project-2\\Proto\\mvps.csv")


playerStatsURL = "https://www.basketball-reference.com/leagues/NBA_{}_per_game.html"

for year in years:
    URL = playerStatsURL.format(year)
    data = requests.get(URL)
    with open("year-2\\sem-4\\ML\\extras\\project-2\\Proto\\player\\{}.html".format(year), "w+", encoding="utf-8") as f:
        f.write(data.text)

# This doesn't return all of the rows of data in the page as this is a JS, which needs to be run in the client side to load all of the data.
# So, I'm using the selenium package to render the webpage from my browser automatically, hence loading in all the data.

driver = webdriver.Chrome(
    executable_path="C:\\Users\\kannu\\OneDrive\\Documents\\coding-related\\chromedriver.exe")

for year in years:
    URL = playerStatsURL.format(year)

    driver.get(URL)
    driver.execute_script("window.scrollTo(1,10000)")
    time.sleep(0.1)

    with open("year-2\\sem-4\\ML\\extras\\project-2\\Proto\\player\\{}.html".format(year), "w+", encoding="utf-8") as f:
        f.write(driver.page_source)

playerDFs = []
for year in years:
    with open("year-2\\sem-4\\ML\\extras\\project-2\\Proto\\player\\{}.html".format(year), encoding="utf-8") as f:
        page = f.read()

    soup = BeautifulSoup(page, 'html.parser')
    soup.find('tr', class_="thead").decompose()
    playerTable = soup.find_all(id="per_game_stats")[0]
    playerDF = pd.read_html(str(playerTable))[0]
    playerDF["Year"] = year
    playerDFs.append(playerDF)

# Returns a pandas DataFrame of data, which contains all the data types on the website, plus a "Year" attribute, which is equal to the season's starting year.
players = pd.concat(playerDFs)

players.to_csv("year-2\\sem-4\\ML\\extras\\project-2\\Proto\\players.csv")

# Moving on to team stats:
teamStatsURL = "https://www.basketball-reference.com/leagues/NBA_{}_standings.html"

# for year in years:
URL = teamStatsURL.format(year)
data = requests.get(URL)

with open("year-2\\sem-4\\ML\\extras\\project-2\\Proto\\team\\{}.html".format(year), "w+", encoding="utf-8") as f:
    f.write(data.text)

teamDFs = []
for year in years:
    with open("year-2\\sem-4\\ML\\extras\\project-2\\Proto\\team\\{}.html".format(year), encoding="utf-8") as f:
        page = f.read()

    soup = BeautifulSoup(page, 'html.parser')
    soup.find('tr', class_="thead").decompose()
    easternTable = soup.find_all(id="divs_standings_E")[0]
    easternDF = pd.read_html(str(easternTable))[0]
    easternDF["Year"] = year
    easternDF["Team"] = easternDF["Eastern Conference"]
    del easternDF["Eastern Conference"]
    teamDFs.append(easternDF)

    westernTable = soup.find_all(id="divs_standings_W")[0]
    westernDF = pd.read_html(str(westernTable))[0]
    westernDF["Year"] = year
    westernDF["Team"] = westernDF["Western Conference"]
    del westernDF["Western Conference"]
    teamDFs.append(westernDF)

teams = pd.concat(teamDFs)
teams.to_csv("year-2\\sem-4\\ML\\extras\\project-2\\Proto\\teams.csv")
