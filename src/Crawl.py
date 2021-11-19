import bs4
import requests as req
import io
import csv


with open("D:\DATA_NEWS\Book1.csv") as f:
    reader = csv.reader(f)
    for row in reader:
        res = req.get(row[1])
        html_doc = res.text
        soup = bs4.BeautifulSoup(html_doc, 'lxml')
        
        match = soup.find('h1',class_='title-detail')

        a = match.string +"\n"
        matches = soup.find_all('p',class_='Normal')
        for tmp in matches:
            a = a + tmp.text + "\n"
        
        i = row[0]
        path = "D:\\DATA_NEWS\\data" + str(i) + ".txt"
        sor = open(path, "w", encoding="utf8")
        sor.write(a)
        sor.close()
