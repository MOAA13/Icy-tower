#pragma once
#include <string>

// Resulotion
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

// Menu
#define MAX_MENU_OPTIONS_COUNT 4

// Position datatype
struct position {
	float x;
	float y;
};

// Game assets
#define MAIN_MENU_BACKGROUND_IMG "assets\\Images\\Menu\\Main\\menu_without_text.png"

// Images
// ===============================Menu===============================
const std::string MAIN_MENU_OPTIONS_IMGS[MAX_MENU_OPTIONS_COUNT][2] =
{
	{
		"assets\\Images\\Menu\\Main\\start_unselected.png",
		"assets\\Images\\Menu\\Main\\start_selected.png"
	},
	{
		"assets\\Images\\Menu\\Main\\options_unselected.png",
		"assets\\Images\\Menu\\Main\\options_selected.png"
	},
	{
		"assets\\Images\\Menu\\Main\\exit_unselected.png",
		"assets\\Images\\Menu\\Main\\exit_selected.png"
	}
};
// ==================================================================

// ===============================Game===============================
#define GAME_BACKGROUND_IMG "assets\\Images\\Game\\game_background.png"
#define SIDE_WALL_IMG "assets\\Images\\Game\\side-wall.png"
#define BLOCK_IMG "assets\\Images\\Game\\block.png"
// ==================================================================

// =============================Temp Character============================
#define CHARACTER_IMG "assets\\Images\\Game\\char.png"
// ==================================================================

// Audio
// ===============================Menu===============================
#define THEME_MUSIC "assets\\Audio\\Menu\\menu_theme_music.wav"
#define MOUTH_CLAP_SOUND "assets\\Audio\\Menu\\mouth_clap_sound.wav"
#define CHOOSE_OPTION_SOUND "assets\\Audio\\Menu\\choose_option_sound.wav"
// ==================================================================

// ===============================Game===============================
#define BLOCK_COLLISION_SOUND "assets\\Audio\\Game\\block_collision_sound.wav"
#define FALL_COLLISION_SOUND "assets\\Audio\\Game\\fall_collision_sound.wav"
// ==================================================================

// =============================Character============================
#define YO_SOUND "assets\\Audio\\Character\\yo_sound.wav"
// ==================================================================

// Fonts 
#define FONT_TYPE "assets\\Font\\pharaonic.ttf"