#pragma once
#include <string>

// Resulotion
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

// Menu
#define MAX_MENU_OPTIONS_COUNT 4

// Game assets
#define MAIN_MENU_BACKGROUND_IMG "assets\\Images\\Menu\\Main\\main_menu_background.png"
#define OPTIONS_MENU_BACKGROUND_IMG "assets\\Images\\Menu\\Options\\options_menu_background.png"

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

const std::string OPTIONS_MENU_OPTIONS_IMGS[MAX_MENU_OPTIONS_COUNT][2] =
{
	{
		"assets\\Images\\Menu\\Options\\theme_music_unselected.png",
		"assets\\Images\\Menu\\Options\\theme_music_selected.png"
	},
	{
		"assets\\Images\\Menu\\Options\\music_volume_unselected.png",
		"assets\\Images\\Menu\\Options\\music_volume_selected.png"
	},
	{
		"assets\\Images\\Menu\\Options\\back_unselected.png",
		"assets\\Images\\Menu\\Options\\back_selected.png"
	}
};
// ==================================================================

// ===============================Game===============================
#define GAME_BACKGROUND_IMG "assets\\Images\\Game\\game_background.png"
#define SIDE_WALL_IMG "assets\\Images\\Game\\side_wall.png"
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
#define FONT_TYPE_1 "assets\\Font\\pharaonic.ttf"
#define FONT_TYPE_2 "assets\\Font\\zombies.ttf"