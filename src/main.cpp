#include <SFML/Graphics.hpp>
#include "Button.h"
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <string>
#include <vector>
#include "WordsList.h"  //для добавления слов из словаря
#include <set> //для хранения угаданных букв
#include <cstdlib> //добавила

#ifdef _WIN32
    #include <windows.h>
#endif

int main()
{
    #ifdef _WIN32
        system("chcp 65001 > nul"); // Переключение консоли на UTF-8
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif
    // system("chcp 65001 > nul");  //добавила
    // SetConsoleOutputCP(CP_UTF8); //добавила
    // SetConsoleCP(CP_UTF8); //добавила
    #ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif
    // Создаем окно
    sf::RenderWindow window(
        sf::VideoMode(sf::Vector2u(800, 600)), 
        "SFML Tutorial - Example 3: Buttons"
    );
    window.setFramerateLimit(60);
    
    // Загрузка шрифта
    // SFML не предоставляет встроенных шрифтов, нужно загрузить свой
    // Для примера используем системный шрифт или создаем простую кнопку без текста
    sf::Font font;
    
    // Попытка загрузить шрифт (если есть)
    // На macOS можно использовать системные шрифты:
    // font.loadFromFile("/System/Library/Fonts/Helvetica.ttc");
    // Или скачать бесплатный шрифт (например, с Google Fonts)
    
    // Если шрифт не загружен, создадим кнопку без текста (только форма)
    bool fontLoaded = false;
    
    // Попытка загрузить шрифт из стандартных мест
    // Используем шрифты с поддержкой кириллицы
    std::vector<std::string> fontPaths = {
    "C:/Windows/Fonts/arial.ttf",          // Стандартный, есть везде, поддерживает кириллицу
    "C:/Windows/Fonts/segoeui.ttf",        // Стандартный шрифт Windows 10/11
    "C:/Windows/Fonts/times.ttf",          // Times New Roman
    "C:/Windows/Fonts/consola.ttf",        // Consola (моноширинный, хорошо для игр)
    "/System/Library/Fonts/Helvetica.ttc", // macOS
    "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf" // Linux
};
    
    for (const auto& path : fontPaths)
    {
        // SFML 3.0: используем openFromFile вместо loadFromFile
        if (font.openFromFile(path))
        {
            fontLoaded = true;
            std::cout << "Шрифт загружен: " << path << std::endl;
            break;
        }
    }
    
    if (!fontLoaded)
    {
        std::cout << "Предупреждение: Шрифт не загружен. Кнопки будут без текста." << std::endl;
        std::cout << "Скачайте бесплатный шрифт с поддержкой кириллицы (например, с Google Fonts)" << std::endl;
        std::cout << "и поместите в resources/font.ttf" << std::endl;
        std::cout << "Рекомендуемые шрифты: Roboto, Open Sans, Noto Sans" << std::endl;
    }
    else
    {
        std::cout << "Примечание: Если видите квадраты вместо текста, шрифт не поддерживает кириллицу." << std::endl;
        std::cout << "Используйте шрифт с поддержкой Unicode (например, Arial Unicode MS или скачайте с Google Fonts)" << std::endl;
    }
    
    //Переменные для окошек
    std::string secretWord = WordList::getRandomWord();  //случайное слово
    std::cout << "Загаданное слово (для теста): " << secretWord << std::endl;  //для проверки

    std::set<char> guessedLetters;  //угаданные буквы
    if (!secretWord.empty()) {
        guessedLetters.insert(secretWord[0]); 
    }

    std::vector<sf::RectangleShape> wordBoxes(7);
    for (int i = 0; i < 7; ++i) {
        wordBoxes[i].setSize(sf::Vector2f(50, 60));
        wordBoxes[i].setFillColor(sf::Color(60, 60, 80));
        wordBoxes[i].setOutlineColor(sf::Color::White);
        wordBoxes[i].setOutlineThickness(2);
        wordBoxes[i].setPosition(sf::Vector2f(150.f + i * 55.f, 100.f)); 
    }

    std::vector<sf::Text> wordLetters;
    wordLetters.reserve(7);
    for (int i = 0; i < 7; ++i) {
        sf::Text txt(font, "", 40);
        txt.setFillColor(sf::Color::White);
        wordLetters.push_back(std::move(txt));
    }

    sf::Texture hangmanTexture;
    sf::Texture hangmanDummyTexture;
    sf::Image hangmanDummyImage(sf::Vector2u(1, 1), sf::Color::Transparent);
    hangmanDummyTexture.loadFromImage(hangmanDummyImage);
    sf::Sprite hangmanSprite(hangmanDummyTexture);
    int mistakesCount = 0;

    //загрузка изображения виселицы  (проверка)
    sf::Image hangmanImage;
    if (hangmanImage.loadFromFile("resources/hangman_0.png"))
    {
        std::cout << "hangmanImage загружен! Размер: " << hangmanImage.getSize().x << "x" << hangmanImage.getSize().y << std::endl;
        
        if (hangmanTexture.loadFromImage(hangmanImage))
        {
            std::cout << " hangmanTexture создана!" << std::endl;
            

            hangmanSprite = sf::Sprite(hangmanTexture);            
            // Масштаби
            float targetHeight = 200.f;
            float scale = targetHeight / static_cast<float>(hangmanTexture.getSize().y);
            hangmanSprite.setScale(sf::Vector2f(scale, scale));
            
            // Позиция
            hangmanSprite.setPosition(sf::Vector2f(580.f, 100.f));
        
        }
        else
        {
            std::cout << "ОШИБКА: Не удалось создать текстуру из изображения" << std::endl;
        }
    }
    else
    {
        std::cout << "ОШИБКА: Не удалось загрузить hangmanImage" << std::endl;
    }


    // Обновляем отображение первой буквы
    if (!secretWord.empty()) {
        wordLetters[0].setString(std::string(1, secretWord[0]));
        sf::FloatRect bounds = wordLetters[0].getLocalBounds();
        wordLetters[0].setOrigin(sf::Vector2f(
            bounds.position.x + bounds.size.x / 2.f,
            bounds.position.y + bounds.size.y / 2.f
        ));
        wordLetters[0].setPosition(sf::Vector2f(
            wordBoxes[0].getPosition().x + wordBoxes[0].getSize().x / 2.f,
            wordBoxes[0].getPosition().y + wordBoxes[0].getSize().y / 2.f
        ));
    }
    
    // Создаем фиктивную текстуру для кнопки (не используется, но требуется конструктором)
    sf::Texture dummyTexture;
    sf::Image dummyImage(sf::Vector2u(1, 1), sf::Color::White);
    if (!dummyTexture.loadFromImage(dummyImage))
    {
        std::cerr << "Ошибка: Не удалось создать фиктивную текстуру!" << std::endl;
    }
    
    // Создаем кнопки
    // Используем английский текст по умолчанию для совместимости
    // Если нужна кириллица, используйте шрифт с поддержкой Unicode (например, Arial Unicode MS)

    std::vector<std::string> buttonTexts = {"A", "B", "C", "D", "Exit", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

    
    // Объявления текстов для кнопок
    std::vector<Button> buttons;
    for (std::string buttonText : buttonTexts) {
        buttons.emplace_back(dummyTexture, buttonText, font, 24);
    }
        
    // Устанавливаем позиции

    for (size_t i = 0; i < buttons.size(); ++i) {
        int column = i / 3;
        int row = i % 3;
        float x = 50 + column * 60;
        float y = 350 + row * 60;
        buttons[i].setPosition(x, y);
    }



    // Настройка цветов
    for (size_t i = 0; i < buttons.size(); ++i) {
    int column = i / 3;
    if (column % 3 == 0) {  // Синие
        buttons[i].setBackgroundColor(sf::Color(70, 130, 180));
        buttons[i].setHoverColor(sf::Color(100, 160, 210));
        buttons[i].setPressedColor(sf::Color(50, 100, 150));
    } else if (column % 3 == 1) {  // Розовые
        buttons[i].setBackgroundColor(sf::Color(180, 70, 130));
        buttons[i].setHoverColor(sf::Color(210, 100, 160));
        buttons[i].setPressedColor(sf::Color(150, 50, 100));
    } else {  // Красные
        buttons[i].setBackgroundColor(sf::Color(180, 70, 70));
        buttons[i].setHoverColor(sf::Color(210, 100, 100));
        buttons[i].setPressedColor(sf::Color(150, 50, 50));
    }
}

//объявляем кнопки
  std::vector<int> clickCounts(buttons.size(), 0);
  
    for (size_t i = 0; i < buttons.size(); ++i) {
        if (i == 4) {  // Кнопка "Exit" 
            buttons[i].setOnClick([&window]() {
                window.close();
            });
        } 
        else {
        // Получаем букву из текста кнопки
            char letter = buttonTexts[i][0];
        
            buttons[i].setOnClick([i, letter, &buttons, &guessedLetters, &secretWord, &wordLetters, &wordBoxes, &mistakesCount, &hangmanTexture, &hangmanSprite]() {
                
                buttons[i].setEnabled(false);
                // Если буква уже была угадана — ничего не делаем
                if (guessedLetters.count(letter)) return;
            
                bool found = false;
                for (size_t pos = 0; pos < secretWord.length(); ++pos) {
                    if (secretWord[pos] == letter) {
                        guessedLetters.insert(letter);
                        wordLetters[pos].setString(std::string(1, letter));
                        // центрирование
                        sf::FloatRect bounds = wordLetters[pos].getLocalBounds();
                        wordLetters[pos].setOrigin(sf::Vector2f(
                            bounds.position.x + bounds.size.x / 2.f,
                            bounds.position.y + bounds.size.y / 2.f
                        ));
                        
                        wordLetters[pos].setPosition(sf::Vector2f(
                            wordBoxes[pos].getPosition().x + wordBoxes[pos].getSize().x / 2.f,
                            wordBoxes[pos].getPosition().y + wordBoxes[pos].getSize().y / 2.f
                        ));
                        found = true;
                    }
                }
            
                if (!found) {
                    std::cout << "Буквы " << letter << " нет в слове!" << std::endl;
                    mistakesCount++;
                if (mistakesCount <= 5){
                    std::string nextPath = "resources/hangman_" + std::to_string(mistakesCount) + ".png";
                    if (hangmanTexture.loadFromFile(nextPath))
                    {
                        hangmanSprite.setTexture(hangmanTexture);
                        // Восстанавливаем масштаб и позицию (SFML 3.0 стиль)
                        float targetHeight = 200.f;
                        float scale = targetHeight / static_cast<float>(hangmanTexture.getSize().y);
                        hangmanSprite.setScale(sf::Vector2f(scale, scale));
                        hangmanSprite.setPosition(sf::Vector2f(580.f, 100.f));
                    }
                }
                
                if (mistakesCount >= 5) {
                    std::cout << "Игра окончена. Слово было: " << secretWord << std::endl;

                    for (size_t j = 0; j < buttons.size(); ++j) {
                    if (j != 4) {  // не трогаем кнопку Exit
                        buttons[j].setEnabled(false);
                        buttons[j].setBackgroundColor(sf::Color(128, 128, 128));  
                        buttons[j].setHoverColor(sf::Color(128, 128, 128));       
                        buttons[j].setPressedColor(sf::Color(100, 100, 100));      
                    }
                }
                }
                }
                
                else {
                    std::cout << "Буква " << letter << " есть!" << std::endl;
                
                    bool win = true;
                    for (char c : secretWord) {
                        if (!guessedLetters.count(c)) {
                            win = false;
                            break;
                        }
                    }
                    if (win) {
                        std::cout << "Ура!!! Слово: " << secretWord << std::endl;
                    }
                }
            });
        }
    }



    std::cout << "Интерактивные кнопки готовы!" << std::endl;
    std::cout << "Наведите мышь на кнопки и нажмите на них." << std::endl;
    
    // Главный цикл
    while (window.isOpen())
    {
        // Обработка событий
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            
            // Передаем события кнопкам (разыменовываем optional)
            sf::Event ev = *event;
            // Обработка событий для всех кнопок
            for (int i = 0; i < buttons.size(); ++i){
                buttons[i].handleEvent(ev, window);
            }

            
            // Обработка ESC
            if (event->is<sf::Event::KeyPressed>())
            {
                auto keyEvent = event->getIf<sf::Event::KeyPressed>();
                if (keyEvent && keyEvent->code == sf::Keyboard::Key::Escape)
                {
                    window.close();
                }
            }
        }
        
        // Обновление кнопок (для обработки движения мыши)

        for (int i = 0; i < buttons.size(); ++i){
                buttons[i].update(window);
            }

        // Очистка экрана
        window.clear(sf::Color(40, 40, 60));
        
        // Отрисовка слова
        for (const auto& box : wordBoxes) {
            window.draw(box);
        }
        for (const auto& txt : wordLetters) {
            if (!txt.getString().isEmpty()) {
                window.draw(txt);
            }
        }

        // Отрисовка кнопок
        for (int i = 0; i < buttons.size(); ++i){
                buttons[i].draw(window);
            }
    

        // Отрисовка изображения
        window.draw(hangmanSprite);

        // Отображение
        window.display();
    }
    
        return 0;
}