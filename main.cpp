#include <SFML/Graphics.hpp>
#include "Button.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
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
        "/System/Library/Fonts/Supplemental/Arial Unicode.ttf",  // macOS - поддерживает кириллицу
        "/System/Library/Fonts/Helvetica.ttc",                    // macOS - fallback
        "/Library/Fonts/Arial.ttf",                              // macOS - альтернатива
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",      // Linux
        "resources/font.ttf"                                     // Локальный
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
    std::string button1Text = fontLoaded ? "A" : "";
    std::string button2Text = fontLoaded ? "B" : "";
    std::string button3Text = fontLoaded ? "C" : "";
    std::string button4Text = fontLoaded ? "D" : "";
    std::string button5Text = fontLoaded ? "Exit" : "";
    std::string button6Text = fontLoaded ? "E" : "";
    std::string button7Text = fontLoaded ? "F" : "";
    std::string button8Text = fontLoaded ? "G" : "";
    std::string button9Text = fontLoaded ? "H" : "";
    std::string button10Text = fontLoaded ? "I" : "";
    std::string button11Text = fontLoaded ? "J" : "";
    std::string button12Text = fontLoaded ? "K" : "";
    std::string button13Text = fontLoaded ? "L" : "";
    std::string button14Text = fontLoaded ? "M" : "";
    std::string button15Text = fontLoaded ? "N" : "";
    std::string button16Text = fontLoaded ? "O" : "";
    std::string button17Text = fontLoaded ? "P" : "";
    std::string button18Text = fontLoaded ? "Q" : "";
    std::string button19Text = fontLoaded ? "R" : "";
    std::string button20Text = fontLoaded ? "S" : "";
    std::string button21Text = fontLoaded ? "T" : "";
    std::string button22Text = fontLoaded ? "U" : "";
    std::string button23Text = fontLoaded ? "V" : "";
    std::string button24Text = fontLoaded ? "W" : "";
    std::string button25Text = fontLoaded ? "X" : "";
    std::string button26Text = fontLoaded ? "Y" : "";
    std::string button27Text = fontLoaded ? "Z" : "";
    
    // Для использования кириллицы раскомментируйте следующие строки
    // и убедитесь, что загружен шрифт с поддержкой кириллицы
    // button1Text = "Кнопка 1";
    // button2Text = "Кнопка 2";
    // button3Text = "Выход";
    
    // Объявления текстов для кнопок

    Button button1(dummyTexture, button1Text, font, 24);
    Button button2(dummyTexture, button2Text, font, 24);
    Button button3(dummyTexture, button3Text, font, 24);
    Button button4(dummyTexture, button4Text, font, 24);
    Button button5(dummyTexture, button5Text, font, 24);
    Button button6(dummyTexture, button6Text, font, 24);
    Button button7(dummyTexture, button7Text, font, 24);
    Button button8(dummyTexture, button8Text, font, 24);
    Button button9(dummyTexture, button9Text, font, 24);
    Button button10(dummyTexture, button10Text, font, 24);
    Button button11(dummyTexture, button11Text, font, 24);
    Button button12(dummyTexture, button12Text, font, 24);
    Button button13(dummyTexture, button13Text, font, 24);
    Button button14(dummyTexture, button14Text, font, 24);
    Button button15(dummyTexture, button15Text, font, 24);
    Button button16(dummyTexture, button16Text, font, 24);
    Button button17(dummyTexture, button17Text, font, 24);
    Button button18(dummyTexture, button18Text, font, 24);
    Button button19(dummyTexture, button19Text, font, 24);
    Button button20(dummyTexture, button20Text, font, 24);
    Button button21(dummyTexture, button21Text, font, 24);
    Button button22(dummyTexture, button22Text, font, 24);
    Button button23(dummyTexture, button23Text, font, 24);
    Button button24(dummyTexture, button24Text, font, 24);
    Button button25(dummyTexture, button25Text, font, 24);
    Button button26(dummyTexture, button26Text, font, 24);
    Button button27(dummyTexture, button27Text, font, 24);
        
    // Устанавливаем позиции
    // Колонка 1 (x = 50)
    button1.setPosition(50, 350);
    button2.setPosition(50, 410);
    button3.setPosition(50, 470);

    // Колонка 2 (x = 110)
    button4.setPosition(110, 350);
    button5.setPosition(110, 410);
    button6.setPosition(110, 470);

    // Колонка 3 (x = 170)
    button7.setPosition(170, 350);
    button8.setPosition(170, 410);
    button9.setPosition(170, 470);

    // Колонка 4 (x = 230)
    button10.setPosition(230, 350);
    button11.setPosition(230, 410);
    button12.setPosition(230, 470);

    // Колонка 5 (x = 290)
    button13.setPosition(290, 350);
    button14.setPosition(290, 410);
    button15.setPosition(290, 470);

    // Колонка 6 (x = 350)
    button16.setPosition(350, 350);
    button17.setPosition(350, 410);
    button18.setPosition(350, 470);

    // Колонка 7 (x = 410)
    button19.setPosition(410, 350);
    button20.setPosition(410, 410);
    button21.setPosition(410, 470);

    // Колонка 8 (x = 470)
    button22.setPosition(470, 350);
    button23.setPosition(470, 410);
    button24.setPosition(470, 470);

    // Колонка 9 (x = 530)
    button25.setPosition(530, 350);
    button26.setPosition(530, 410);
    button27.setPosition(530, 470);


    // Настройка цветов

    // === Колонка 1 (Синие) ===
    button1.setBackgroundColor(sf::Color(70, 130, 180));
    button1.setHoverColor(sf::Color(100, 160, 210));
    button1.setPressedColor(sf::Color(50, 100, 150));

    button2.setBackgroundColor(sf::Color(70, 130, 180));
    button2.setHoverColor(sf::Color(100, 160, 210));
    button2.setPressedColor(sf::Color(50, 100, 150));

    button3.setBackgroundColor(sf::Color(70, 130, 180));
    button3.setHoverColor(sf::Color(100, 160, 210));
    button3.setPressedColor(sf::Color(50, 100, 150));

    // === Колонка 2 (Розовые) ===
    button4.setBackgroundColor(sf::Color(180, 70, 130));
    button4.setHoverColor(sf::Color(210, 100, 160));
    button4.setPressedColor(sf::Color(150, 50, 100));

    button5.setBackgroundColor(sf::Color(180, 70, 130));
    button5.setHoverColor(sf::Color(210, 100, 160));
    button5.setPressedColor(sf::Color(150, 50, 100));

    button6.setBackgroundColor(sf::Color(180, 70, 130));
    button6.setHoverColor(sf::Color(210, 100, 160));
    button6.setPressedColor(sf::Color(150, 50, 100));

    // === Колонка 3 (Красные) ===
    button7.setBackgroundColor(sf::Color(180, 70, 70));
    button7.setHoverColor(sf::Color(210, 100, 100));
    button7.setPressedColor(sf::Color(150, 50, 50));

    button8.setBackgroundColor(sf::Color(180, 70, 70));
    button8.setHoverColor(sf::Color(210, 100, 100));
    button8.setPressedColor(sf::Color(150, 50, 50));

    button9.setBackgroundColor(sf::Color(180, 70, 70));
    button9.setHoverColor(sf::Color(210, 100, 100));
    button9.setPressedColor(sf::Color(150, 50, 50));

    // === Колонка 4 (Синие) ===
    button10.setBackgroundColor(sf::Color(70, 130, 180));
    button10.setHoverColor(sf::Color(100, 160, 210));
    button10.setPressedColor(sf::Color(50, 100, 150));

    button11.setBackgroundColor(sf::Color(70, 130, 180));
    button11.setHoverColor(sf::Color(100, 160, 210));
    button11.setPressedColor(sf::Color(50, 100, 150));

    button12.setBackgroundColor(sf::Color(70, 130, 180));
    button12.setHoverColor(sf::Color(100, 160, 210));
    button12.setPressedColor(sf::Color(50, 100, 150));

    // === Колонка 5 (Розовые) ===
    button13.setBackgroundColor(sf::Color(180, 70, 130));
    button13.setHoverColor(sf::Color(210, 100, 160));
    button13.setPressedColor(sf::Color(150, 50, 100));

    button14.setBackgroundColor(sf::Color(180, 70, 130));
    button14.setHoverColor(sf::Color(210, 100, 160));
    button14.setPressedColor(sf::Color(150, 50, 100));

    button15.setBackgroundColor(sf::Color(180, 70, 130));
    button15.setHoverColor(sf::Color(210, 100, 160));
    button15.setPressedColor(sf::Color(150, 50, 100));

    // === Колонка 6 (Красные) ===
    button16.setBackgroundColor(sf::Color(180, 70, 70));
    button16.setHoverColor(sf::Color(210, 100, 100));
    button16.setPressedColor(sf::Color(150, 50, 50));

    button17.setBackgroundColor(sf::Color(180, 70, 70));
    button17.setHoverColor(sf::Color(210, 100, 100));
    button17.setPressedColor(sf::Color(150, 50, 50));

    button18.setBackgroundColor(sf::Color(180, 70, 70));
    button18.setHoverColor(sf::Color(210, 100, 100));
    button18.setPressedColor(sf::Color(150, 50, 50));

    // === Колонка 7 (Синие) ===
    button19.setBackgroundColor(sf::Color(70, 130, 180));
    button19.setHoverColor(sf::Color(100, 160, 210));
    button19.setPressedColor(sf::Color(50, 100, 150));

    button20.setBackgroundColor(sf::Color(70, 130, 180));
    button20.setHoverColor(sf::Color(100, 160, 210));
    button20.setPressedColor(sf::Color(50, 100, 150));

    button21.setBackgroundColor(sf::Color(70, 130, 180));
    button21.setHoverColor(sf::Color(100, 160, 210));
    button21.setPressedColor(sf::Color(50, 100, 150));

    // === Колонка 8 (Розовые) ===
    button22.setBackgroundColor(sf::Color(180, 70, 130));
    button22.setHoverColor(sf::Color(210, 100, 160));
    button22.setPressedColor(sf::Color(150, 50, 100));

    button23.setBackgroundColor(sf::Color(180, 70, 130));
    button23.setHoverColor(sf::Color(210, 100, 160));
    button23.setPressedColor(sf::Color(150, 50, 100));

    button24.setBackgroundColor(sf::Color(180, 70, 130));
    button24.setHoverColor(sf::Color(210, 100, 160));
    button24.setPressedColor(sf::Color(150, 50, 100));

    // === Колонка 9 (Красные) ===
    button25.setBackgroundColor(sf::Color(180, 70, 70));
    button25.setHoverColor(sf::Color(210, 100, 100));
    button25.setPressedColor(sf::Color(150, 50, 50));

    button26.setBackgroundColor(sf::Color(180, 70, 70));
    button26.setHoverColor(sf::Color(210, 100, 100));
    button26.setPressedColor(sf::Color(150, 50, 50));

    button27.setBackgroundColor(sf::Color(180, 70, 70));
    button27.setHoverColor(sf::Color(210, 100, 100));
    button27.setPressedColor(sf::Color(150, 50, 50));

    // Устанавливаем callback функции
    int clickCount1 = 0;
    int clickCount2 = 0;
    int clickCount3 = 0;
    int clickCount4 = 0;
    int clickCount5 = 0;
    int clickCount6 = 0;
    int clickCount7 = 0;
    int clickCount8 = 0;
    int clickCount9 = 0;
    int clickCount10 = 0;
    int clickCount11 = 0;
    int clickCount12 = 0;
    int clickCount13 = 0;
    int clickCount14 = 0;
    int clickCount15 = 0;
    int clickCount16 = 0;
    int clickCount17 = 0;
    int clickCount18 = 0;
    int clickCount19 = 0;
    int clickCount20 = 0;
    int clickCount21 = 0;
    int clickCount22 = 0;
    int clickCount23 = 0;
    int clickCount24 = 0;
    int clickCount25 = 0;
    int clickCount26 = 0;
    int clickCount27 = 0;
    
    
    button1.setOnClick([&clickCount1]() {
        clickCount1++;
        std::cout << "Кнопка 1 нажата! Счетчик: " << clickCount1 << std::endl;
    });
    
    button2.setOnClick([&clickCount2]() {
        clickCount2++;
        std::cout << "Кнопка 2 нажата! Счетчик: " << clickCount2 << std::endl;
    });
    
    button3.setOnClick([&clickCount3]() {
        clickCount3++;
        std::cout << "Кнопка 3 нажата! Счетчик: " << clickCount3 << std::endl;
    });
    
     button4.setOnClick([&clickCount4]() {
        clickCount4++;
        std::cout << "Кнопка 4 нажата! Счетчик: " << clickCount4 << std::endl;
    });
    
    button5.setOnClick([&window]() {
        std::cout << "Выход из приложения..." << std::endl;
        window.close();
    });

    button6.setOnClick([&clickCount6]() {
    clickCount6++;
    std::cout << "Кнопка 6 нажата! Счетчик: " << clickCount6 << std::endl;
    });

    button7.setOnClick([&clickCount7]() {
        clickCount7++;
        std::cout << "Кнопка 7 нажата! Счетчик: " << clickCount7 << std::endl;
    });

    button8.setOnClick([&clickCount8]() {
        clickCount8++;
        std::cout << "Кнопка 8 нажата! Счетчик: " << clickCount8 << std::endl;
    });

    button9.setOnClick([&clickCount9]() {
        clickCount9++;
        std::cout << "Кнопка 9 нажата! Счетчик: " << clickCount9 << std::endl;
    });

    button10.setOnClick([&clickCount10]() {
        clickCount10++;
        std::cout << "Кнопка 10 нажата! Счетчик: " << clickCount10 << std::endl;
    });

    button11.setOnClick([&clickCount11]() {
        clickCount11++;
        std::cout << "Кнопка 11 нажата! Счетчик: " << clickCount11 << std::endl;
    });

    button12.setOnClick([&clickCount12]() {
        clickCount12++;
        std::cout << "Кнопка 12 нажата! Счетчик: " << clickCount12 << std::endl;
    });

    button13.setOnClick([&clickCount13]() {
        clickCount13++;
        std::cout << "Кнопка 13 нажата! Счетчик: " << clickCount13 << std::endl;
    });

    button14.setOnClick([&clickCount14]() {
        clickCount14++;
        std::cout << "Кнопка 14 нажата! Счетчик: " << clickCount14 << std::endl;
    });

    button15.setOnClick([&clickCount15]() {
        clickCount15++;
        std::cout << "Кнопка 15 нажата! Счетчик: " << clickCount15 << std::endl;
    });

    button16.setOnClick([&clickCount16]() {
        clickCount16++;
        std::cout << "Кнопка 16 нажата! Счетчик: " << clickCount16 << std::endl;
    });

    button17.setOnClick([&clickCount17]() {
        clickCount17++;
        std::cout << "Кнопка 17 нажата! Счетчик: " << clickCount17 << std::endl;
    });

    button18.setOnClick([&clickCount18]() {
        clickCount18++;
        std::cout << "Кнопка 18 нажата! Счетчик: " << clickCount18 << std::endl;
    });

    button19.setOnClick([&clickCount19]() {
        clickCount19++;
        std::cout << "Кнопка 19 нажата! Счетчик: " << clickCount19 << std::endl;
    });

    button20.setOnClick([&clickCount20]() {
        clickCount20++;
        std::cout << "Кнопка 20 нажата! Счетчик: " << clickCount20 << std::endl;
    });

    button21.setOnClick([&clickCount21]() {
        clickCount21++;
        std::cout << "Кнопка 21 нажата! Счетчик: " << clickCount21 << std::endl;
    });

    button22.setOnClick([&clickCount22]() {
        clickCount22++;
        std::cout << "Кнопка 22 нажата! Счетчик: " << clickCount22 << std::endl;
    });

    button23.setOnClick([&clickCount23]() {
        clickCount23++;
        std::cout << "Кнопка 23 нажата! Счетчик: " << clickCount23 << std::endl;
    });

    button24.setOnClick([&clickCount24]() {
        clickCount24++;
        std::cout << "Кнопка 24 нажата! Счетчик: " << clickCount24 << std::endl;
    });

    button25.setOnClick([&clickCount25]() {
        clickCount25++;
        std::cout << "Кнопка 25 нажата! Счетчик: " << clickCount25 << std::endl;
    });

    button26.setOnClick([&clickCount26]() {
        clickCount26++;
        std::cout << "Кнопка 26 нажата! Счетчик: " << clickCount26 << std::endl;
    });

    button27.setOnClick([&clickCount27]() {
        clickCount27++;
        std::cout << "Кнопка 27 нажата! Счетчик: " << clickCount27 << std::endl;
    });

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
            button1.handleEvent(ev, window);
            button2.handleEvent(ev, window);
            button3.handleEvent(ev, window);
            button4.handleEvent(ev, window);
            button5.handleEvent(ev, window);
            button6.handleEvent(ev, window);
            button7.handleEvent(ev, window);
            button8.handleEvent(ev, window);
            button9.handleEvent(ev, window);
            button10.handleEvent(ev, window);
            button11.handleEvent(ev, window);
            button12.handleEvent(ev, window);
            button13.handleEvent(ev, window);
            button14.handleEvent(ev, window);
            button15.handleEvent(ev, window);
            button16.handleEvent(ev, window);
            button17.handleEvent(ev, window);
            button18.handleEvent(ev, window);
            button19.handleEvent(ev, window);
            button20.handleEvent(ev, window);
            button21.handleEvent(ev, window);
            button22.handleEvent(ev, window);
            button23.handleEvent(ev, window);
            button24.handleEvent(ev, window);
            button25.handleEvent(ev, window);
            button26.handleEvent(ev, window);
            button27.handleEvent(ev, window);
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
        button1.update(window);
        button2.update(window);
        button3.update(window);
        button4.update(window);
        button5.update(window);
        button6.update(window);
        button7.update(window);
        button8.update(window);
        button9.update(window);
        button10.update(window);
        button11.update(window);
        button12.update(window);
        button13.update(window);
        button14.update(window);
        button15.update(window);
        button16.update(window);
        button17.update(window);
        button18.update(window);
        button19.update(window);
        button20.update(window);
        button21.update(window);
        button22.update(window);
        button23.update(window);
        button24.update(window);
        button25.update(window);
        button26.update(window);
        button27.update(window);

        // Очистка экрана
        window.clear(sf::Color(40, 40, 60));
        
        // Отрисовка кнопок
        button1.draw(window);
        button2.draw(window);
        button3.draw(window);
        button4.draw(window);
        button5.draw(window);
        button6.draw(window);
        button7.draw(window);
        button8.draw(window);
        button9.draw(window);
        button10.draw(window);
        button11.draw(window);
        button12.draw(window);
        button13.draw(window);
        button14.draw(window);
        button15.draw(window);
        button16.draw(window);
        button17.draw(window);
        button18.draw(window);
        button19.draw(window);
        button20.draw(window);
        button21.draw(window);
        button22.draw(window);
        button23.draw(window);
        button24.draw(window);
        button25.draw(window);
        button26.draw(window);
        button27.draw(window);
        // Отображение
        window.display();
    }
    
    std::cout << "Приложение завершено." << std::endl;
    std::cout << "Кнопка 1 была нажата " << clickCount1 << " раз(а)." << std::endl;
    std::cout << "Кнопка 2 была нажата " << clickCount2 << " раз(а)." << std::endl;
    std::cout << "Кнопка 3 была нажата " << clickCount3 << " раз(а)." << std::endl;
    std::cout << "Кнопка 4 была нажата " << clickCount4 << " раз(а)." << std::endl;
    std::cout << "Кнопка 6 была нажата " << clickCount6 << " раз(а)." << std::endl;
    std::cout << "Кнопка 7 была нажата " << clickCount7 << " раз(а)." << std::endl;
    std::cout << "Кнопка 8 была нажата " << clickCount8 << " раз(а)." << std::endl;
    std::cout << "Кнопка 9 была нажата " << clickCount9 << " раз(а)." << std::endl;
    std::cout << "Кнопка 10 была нажата " << clickCount10 << " раз(а)." << std::endl;
    std::cout << "Кнопка 11 была нажата " << clickCount11 << " раз(а)." << std::endl;
    std::cout << "Кнопка 12 была нажата " << clickCount12 << " раз(а)." << std::endl;
    std::cout << "Кнопка 13 была нажата " << clickCount13 << " раз(а)." << std::endl;
    std::cout << "Кнопка 14 была нажата " << clickCount14 << " раз(а)." << std::endl;
    std::cout << "Кнопка 15 была нажата " << clickCount15 << " раз(а)." << std::endl;
    std::cout << "Кнопка 16 была нажата " << clickCount16 << " раз(а)." << std::endl;
    std::cout << "Кнопка 17 была нажата " << clickCount17 << " раз(а)." << std::endl;
    std::cout << "Кнопка 18 была нажата " << clickCount18 << " раз(а)." << std::endl;
    std::cout << "Кнопка 19 была нажата " << clickCount19 << " раз(а)." << std::endl;
    std::cout << "Кнопка 20 была нажата " << clickCount20 << " раз(а)." << std::endl;
    std::cout << "Кнопка 21 была нажата " << clickCount21 << " раз(а)." << std::endl;
    std::cout << "Кнопка 22 была нажата " << clickCount22 << " раз(а)." << std::endl;
    std::cout << "Кнопка 23 была нажата " << clickCount23 << " раз(а)." << std::endl;
    std::cout << "Кнопка 24 была нажата " << clickCount24 << " раз(а)." << std::endl;
    std::cout << "Кнопка 25 была нажата " << clickCount25 << " раз(а)." << std::endl;
    std::cout << "Кнопка 26 была нажата " << clickCount26 << " раз(а)." << std::endl;
    std::cout << "Кнопка 27 была нажата " << clickCount27 << " раз(а)." << std::endl;
    return 0;
}
