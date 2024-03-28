import os
from selenium import webdriver
from selenium.webdriver.common.by import By

form_link = "https://docs.google.com/forms/d/e/1FAIpQLSeYE5oKTpILggujs0EhdI765ejmhKxECFKYwU6emK2_cwBa7g/viewform"
# form_link = "https://docs.google.com/forms/d/e/1FAIpQLScSZzLetdC7yvCmpkmn7fVEcMdhSkmpXIGdMTqVcuRmlgnrwQ/formrestricted"


person_1_data = {"Last Name": "Boerhout", "First Name": "Sean", "ID": "12345"}
all_data = [person_1_data]


def reset_form():
    submit_another = browser.find_element(
        By.XPATH, "/html/body/div[1]/div[2]/div[1]/div/div[4]/a"
    )
    submit_another.click()


def main():
    textboxes = browser.find_elements(
        By.CLASS_NAME, "quantumWizTextinputPaperinputInput"
    )
    checkbox = browser.find_element(By.XPATH, '//*[@id="i18"]/div[2]')
    submit_button = browser.find_element(
        By.XPATH, '//*[@id="mG61Hd"]/div[2]/div/div[3]/div[1]/div[1]/div/span'
    )

    for person in all_data:
        textboxes[0].send_keys(person["Last Name"])
        textboxes[1].send_keys(person["First Name"])
        textboxes[2].send_keys(person["ID"])
        checkbox.click()
        submit_button.click()

        # reset_form()


if __name__ == "__main__":
    option = webdriver.ChromeOptions()
    option.add_argument("-incognito")
    # option.add_argument("--headless")

    PROJECT_ROOT = os.path.abspath(os.path.dirname(__file__))
    DRIVER_PATH = os.path.join(PROJECT_ROOT, "chromedriver")

    browser = webdriver.Chrome(DRIVER_PATH)
    browser.get(form_link)

    main()

    browser.close()
