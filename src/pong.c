#include <stdio.h>

#define FIELD_HEIGHT 80
#define FIELD_WIDTH 25

#define MOVE_SKIP 0
#define MOVE_DOWN 1
#define MOVE_UP 2

#define RACKET_SIZE 3

#define MIN_RACKET_POSITION 0
#define MAX_RACKET_POSITION 10

typedef enum {
    // Отсутствие направления
    DIR_NONE = 0,

    // Основные направления (по часовой стрелке)
    DIR_NORTH = 1,      // Север (вверх)
    DIR_NORTHEAST = 2,  // Северо-восток
    DIR_EAST = 3,       // Восток (вправо)
    DIR_SOUTHEAST = 4,  // Юго-восток
    DIR_SOUTH = 5,      // Юг (вниз)
    DIR_SOUTHWEST = 6,  // Юго-запад
    DIR_WEST = 7,       // Запад (влево)
    DIR_NORTHWEST = 8   // Северо-запад
} Direction;

void render_field(int first_racket_pos, int second_racket_pos, int ball_x, int ball_y,
                  int first_player_scores, int second_player_scores);
void render_end();
void handle_players_moves(int *first_player_move, int *second_player_move);
void move_rackets(int *first_racket_pos, int first_player_move, int *second_racket_pos,
                  int second_player_move);
void move_ball(int *ball_x, int *ball_y, Direction *ball_vector, int *is_goal);
void check_goal(int ball_x, int ball_y, int *is_goal, int is_first_player_goal);
void changing_scores(int *player_scores);
void check_winner(int first_player_scores, int second_player_scores, int *is_end);

int main() {
    int first_racket_pos = 5;
    int second_racket_pos = 5;

    int first_player_move = 0;
    int second_player_move = 0;

    int first_player_scores = 0;
    int second_player_scores = 0;

    int ball_x;
    int ball_y;
    Direction ball_vector;

    int is_goal = 0;
    int is_first_player_goal = 0;

    int is_end = 0;

    while (1) {
        if (is_end) {
            // render_end();
        } else {
            printf("%d %d\n", first_racket_pos, second_racket_pos);
            // render_field(first_racket_pos, second_racket_pos, ball_x, ball_y);
        }

        if (is_end) {
            return 0;
        }

        // handle_players_moves(&first_player_move, &second_player_move);
        scanf("%d %d", &first_player_move, &second_player_move);

        move_rackets(&first_racket_pos, first_player_move, &second_racket_pos, second_player_move);

        continue;

        move_ball(&ball_x, &ball_y, &ball_vector, &is_goal);

        check_goal(ball_x, ball_y, &is_goal, is_first_player_goal);

        if (is_goal) {
            changing_scores(is_first_player_goal ? &first_player_scores : &second_player_scores);

            check_winner(first_player_scores, second_player_scores, &is_end);
        }
    }

    return 0;
}

void move_one_racket(int *racket_pos, int player_move) {
    switch (player_move) {
        case MOVE_DOWN:
            if (*racket_pos > MIN_RACKET_POSITION) *racket_pos -= 1;
            break;
        case MOVE_UP:
            if (*racket_pos < MAX_RACKET_POSITION) *racket_pos += 1;
            break;
    }
}

void move_rackets(int *first_racket_pos, int first_player_move, int *second_racket_pos,
                  int second_player_move) {
    move_one_racket(first_racket_pos, first_player_move);
    move_one_racket(second_racket_pos, second_player_move);
}
