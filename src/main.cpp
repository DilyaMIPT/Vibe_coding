#include <SFML/Graphics.hpp>
#include "Button.h"
#include <iostream>
#include <string>
#include <vector>
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
    
    // Создаем фиктивную текстуру для кнопки (не используется, но требуется конструктором)
    // SFML 3.0: создаем текстуру через Image, так как create() удален
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
                std::cout << "Выход..." << std::endl;
                window.close();
            });
        } else {  // Все остальные
            buttons[i].setOnClick([i, &buttons, &clickCounts]() {
                clickCounts[i]++;
                std::cout << "Кнопка " << (i+1) << " нажата! Счетчик: " 
                        << clickCounts[i] << std::endl;
                buttons[i].setEnabled(false);
            });
        }
    }

    // // Устанавливаем callback функции
    // for (int i = 0; i < buttons.size(); ++i){
    //     clickCounts[i] = 0;
    // }
    
    // for (int i = 0; i < buttons.size(); ++i){
    //     buttons[i].setOnClick([i, &buttons, &clickCounts]() {
    //     clickCounts[i]++;
    //     std::cout << "Кнопка " << (i+1) << " нажата! Счетчик: " << clickCounts[i] << std::endl;
    //     buttons[i].setEnabled(false);
    //     });
    // }


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
        
        // Отрисовка кнопок
        for (int i = 0; i < buttons.size(); ++i){
                buttons[i].draw(window);
            }
        // Отображение
        window.display();
    }
    

    std::cout << "Приложение завершено." << std::endl;
    for (int i = 0; i < buttons.size(); ++i){
        std::cout << "Кнопка"<< i << "была нажата " << clickCounts[i] << " раз(а)." << std::endl;
    }
        return 0;
}
