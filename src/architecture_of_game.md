# Архитектура игры

## Техническое задание
- 2 игрока
- счет голов
- конец игры после получения 21 очка
- пошаговая режим игры
- a/z для первого игрока
- k/m для второго игрока
- поле размером 80х25
- размер ракетки - 3 символа
- размер мяча 1 символ
- запрещено использовать динамическую память
- запрещено использовать массивы
- для отображения графики можно использовать только ascii

## Структура кода
1. Отрисовка поля
1. Обработка действий игроков
1. Передвижение ракеток
1. Передвижение мячика
1. Проверка гола
    1. Изменение очков игроков
    1. Проверка победителя

## Переменные и константы
    #define FIELD_HEIGHT 80
    #define FIELD_WIDTH 25

    #define MOVE_SKIP 0
    #define MOVE_DOWN 1
    #define MOVE_UP 2

    int first_racket_pos
    int second_racket_pos

    int first_player_move
    int second_player_move

    int first_player_scores
    int second_player_scores

    int ball_x
    int ball_y
    int ball_vector
    int ball_speed

    int is_end

## Отрисовка поля
    void render_field(&first_racket_pos, &second_racket_pos, &is_end)

## Проверка завершения игры
if is_end then return

## Обработка действий игроков
    void handle_players_moves(&first_player_move, &second_player_move)

    first_player_move = \<code\>
    second_player_move = \<code\>

## Передвижение ракеток
    void move_rackets(&first_racket_pos, &first_player_move, &second_racket_pos, &second_player_move)

    first_racket_pos = \<new position\>
    second_racket_pos = \<new position\>

## Передвижение мячика
    void move_ball(&ball_x, &ball_y, &ball_vector, &ball_speed)

    int ball_x = \<new value\>
    int ball_y = \<new value\>

    int ball_vector = \<new value\>
    int ball_speed = \<new value\>

## Проверка гола
    void check_goal(&ball_x, &ball_y)

    void changing_scores(&player_scores)
    void check_winner(&first_player_scores, &second_player_scores)
