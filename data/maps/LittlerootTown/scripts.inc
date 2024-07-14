LittlerootTown_MapScripts::
# 36 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
# 37 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 38 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, StepOffTruck
	.2byte 0


LittlerootTown_OnTransition::
# 43 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_WATERLOO_TOWN
# 44 "data/maps/LittlerootTown/scripts.pory"
	goto_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_OnTransition_2
LittlerootTown_OnTransition_1:
# 47 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 3
	goto_if_eq LittlerootTown_OnTransition_5
LittlerootTown_OnTransition_4:
# 50 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_eq LittlerootTown_OnTransition_8
LittlerootTown_OnTransition_7:
	end

LittlerootTown_OnTransition_2:
# 45 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetTwinPos
	goto LittlerootTown_OnTransition_1

LittlerootTown_OnTransition_5:
# 48 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
	goto LittlerootTown_OnTransition_4

LittlerootTown_OnTransition_8:
# 52 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	goto LittlerootTown_OnTransition_7


LittlerootTown_EventScript_SetTwinPos::
# 59 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_eq LittlerootTown_EventScript_SetTwinPos_2
LittlerootTown_EventScript_SetTwinPos_1:
# 63 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 10, 1
# 64 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return

LittlerootTown_EventScript_SetTwinPos_2:
# 60 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 7, 2
# 61 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	goto LittlerootTown_EventScript_SetTwinPos_1


LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
# 69 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 70 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
# 71 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 5, 9
	return


LittlerootTown_EventScript_GoInsideWithMom::
# 76 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 77 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 78 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 79 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 80 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_GoInsideWithMom_Text_0
# 81 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 82 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 83 "data/maps/LittlerootTown/scripts.pory"
	opendoor 5, 8
# 84 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 85 "data/maps/LittlerootTown/scripts.pory"
	addobject 4
# 86 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitHouse
# 87 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 88 "data/maps/LittlerootTown/scripts.pory"
	closedoor 5, 8
# 89 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 90 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 91 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 92 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 93 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside
# 94 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 95 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachDoor
# 96 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 97 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 98 "data/maps/LittlerootTown/scripts.pory"
	opendoor 5, 8
# 99 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 100 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomEnterHouse
# 101 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 102 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 103 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 104 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 105 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 106 "data/maps/LittlerootTown/scripts.pory"
	closedoor 5, 8
# 107 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 108 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 109 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 110 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 111 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 112 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 113 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


StepOffTruck::
# 119 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 122 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GoInsideWithMom
	return


# 126 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 127 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 128 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 129 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 130 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 131 "data/maps/LittlerootTown/scripts.pory"
	step_end

# 134 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 135 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 136 "data/maps/LittlerootTown/scripts.pory"
	step_end

# 139 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 140 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 141 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
# 142 "data/maps/LittlerootTown/scripts.pory"
	step_end

# 145 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 146 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 147 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 148 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 149 "data/maps/LittlerootTown/scripts.pory"
	step_end

# 152 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 153 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 154 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
# 155 "data/maps/LittlerootTown/scripts.pory"
	step_end

# 158 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 159 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 160 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 161 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 162 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 163 "data/maps/LittlerootTown/scripts.pory"
	step_end

# 166 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 167 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 168 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 169 "data/maps/LittlerootTown/scripts.pory"
	step_end

killMom::
# 174 "data/maps/LittlerootTown/scripts.pory"
	msgbox killMom_Text_0
# 175 "data/maps/LittlerootTown/scripts.pory"
	closemessage
	return


# 179 "data/maps/LittlerootTown/scripts.pory"

# 180 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_FatMan::
# 181 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 182 "data/maps/LittlerootTown/scripts.pory"
	end
# 183 "data/maps/LittlerootTown/scripts.pory"

# 184 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Boy::
# 185 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 186 "data/maps/LittlerootTown/scripts.pory"
	end
# 187 "data/maps/LittlerootTown/scripts.pory"

# 188 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Twin::
# 189 "data/maps/LittlerootTown/scripts.pory"
	lock
# 190 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 191 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 192 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 193 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_GoSaveBirch
# 194 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 195 "data/maps/LittlerootTown/scripts.pory"
	release
# 196 "data/maps/LittlerootTown/scripts.pory"
	end
# 197 "data/maps/LittlerootTown/scripts.pory"

# 198 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirch::
# 199 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 200 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 201 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 202 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 203 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 204 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 205 "data/maps/LittlerootTown/scripts.pory"
	release
# 206 "data/maps/LittlerootTown/scripts.pory"
	end
# 207 "data/maps/LittlerootTown/scripts.pory"

# 208 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_YouSavedBirch::
# 209 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 210 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 211 "data/maps/LittlerootTown/scripts.pory"
	release
# 212 "data/maps/LittlerootTown/scripts.pory"
	end
# 213 "data/maps/LittlerootTown/scripts.pory"

# 214 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoodLuck::
# 215 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 216 "data/maps/LittlerootTown/scripts.pory"
	release
# 217 "data/maps/LittlerootTown/scripts.pory"
	end
# 218 "data/maps/LittlerootTown/scripts.pory"

# 219 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 220 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 221 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
# 222 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 223 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 224 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnLeft
# 225 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 226 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 227 "data/maps/LittlerootTown/scripts.pory"
	end
# 228 "data/maps/LittlerootTown/scripts.pory"

# 229 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DangerousWithoutPokemon::
# 230 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 231 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 232 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 233 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 234 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 235 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 236 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 237 "data/maps/LittlerootTown/scripts.pory"
	return
# 238 "data/maps/LittlerootTown/scripts.pory"

# 239 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 240 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 241 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 242 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 243 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 244 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 245 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 246 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 247 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 248 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 249 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 250 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 251 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 252 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 253 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 254 "data/maps/LittlerootTown/scripts.pory"

# 255 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 256 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 257 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 258 "data/maps/LittlerootTown/scripts.pory"

# 259 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 260 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 261 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 262 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 263 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 264 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 265 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 266 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 267 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 268 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 269 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 270 "data/maps/LittlerootTown/scripts.pory"

# 271 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 272 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 273 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 274 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
# 275 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 276 "data/maps/LittlerootTown/scripts.pory"

# 277 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 278 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 279 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
# 280 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 281 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 282 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnRight
# 283 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 284 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 285 "data/maps/LittlerootTown/scripts.pory"
	end
# 286 "data/maps/LittlerootTown/scripts.pory"

# 287 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 288 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 289 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 290 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 291 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 292 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 293 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 294 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 295 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 296 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 297 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 298 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 299 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 300 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 301 "data/maps/LittlerootTown/scripts.pory"

# 302 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 303 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 304 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 305 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 306 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 307 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 308 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 309 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 310 "data/maps/LittlerootTown/scripts.pory"

# 311 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirchTrigger::
# 312 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 313 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterRight
# 314 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 315 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 316 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 317 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 318 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 319 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 320 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 321 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 322 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 323 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 324 "data/maps/LittlerootTown/scripts.pory"
	end
# 325 "data/maps/LittlerootTown/scripts.pory"

# 326 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_TownSign::
# 327 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 328 "data/maps/LittlerootTown/scripts.pory"
	end
# 329 "data/maps/LittlerootTown/scripts.pory"

# 330 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsLabSign::
# 331 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 332 "data/maps/LittlerootTown/scripts.pory"
	end
# 333 "data/maps/LittlerootTown/scripts.pory"

# 334 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BrendansHouseSign::
# 335 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 336 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_PlayersHouseSignMale
# 337 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 338 "data/maps/LittlerootTown/scripts.pory"
	end
# 339 "data/maps/LittlerootTown/scripts.pory"

# 340 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignMale::
# 341 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 342 "data/maps/LittlerootTown/scripts.pory"
	return
# 343 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MaysHouseSign::
# 344 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 345 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 346 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_BirchsHouseSignMale
# 347 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignFemale
# 348 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 349 "data/maps/LittlerootTown/scripts.pory"
	end
# 350 "data/maps/LittlerootTown/scripts.pory"

# 351 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignMale::
# 352 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 353 "data/maps/LittlerootTown/scripts.pory"
	return
# 354 "data/maps/LittlerootTown/scripts.pory"

# 355 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignFemale::
# 356 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 357 "data/maps/LittlerootTown/scripts.pory"
	return
# 358 "data/maps/LittlerootTown/scripts.pory"

# 359 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 360 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 361 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 362 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 10, 9
# 363 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 364 "data/maps/LittlerootTown/scripts.pory"
	end
# 365 "data/maps/LittlerootTown/scripts.pory"

# 366 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 367 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 368 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 369 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 11, 9
# 370 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 371 "data/maps/LittlerootTown/scripts.pory"
	end
# 372 "data/maps/LittlerootTown/scripts.pory"

# 373 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 374 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 375 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 376 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 377 "data/maps/LittlerootTown/scripts.pory"
	end
# 378 "data/maps/LittlerootTown/scripts.pory"

# 379 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 380 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 381 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 382 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 383 "data/maps/LittlerootTown/scripts.pory"
	end
# 384 "data/maps/LittlerootTown/scripts.pory"

# 385 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 386 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 387 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 388 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 389 "data/maps/LittlerootTown/scripts.pory"
	end
# 390 "data/maps/LittlerootTown/scripts.pory"

# 391 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 392 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 393 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 394 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 395 "data/maps/LittlerootTown/scripts.pory"
	end
# 396 "data/maps/LittlerootTown/scripts.pory"

# 397 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 398 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 399 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomNoticePlayerMale
# 400 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomNoticePlayerFemale
# 401 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 402 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 403 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 404 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 405 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 406 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 407 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomApproachPlayerMale
# 408 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomApproachPlayerFemale
# 409 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 410 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 411 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomReturnHomeMale
# 412 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomReturnHomeFemale
# 413 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 414 "data/maps/LittlerootTown/scripts.pory"
	end
# 415 "data/maps/LittlerootTown/scripts.pory"

# 416 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsMale::
# 417 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 418 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 419 "data/maps/LittlerootTown/scripts.pory"
	return
# 420 "data/maps/LittlerootTown/scripts.pory"

# 421 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
# 422 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 423 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 424 "data/maps/LittlerootTown/scripts.pory"
	return
# 425 "data/maps/LittlerootTown/scripts.pory"

# 426 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerMale::
# 427 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterRight
# 428 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 429 "data/maps/LittlerootTown/scripts.pory"
	return
# 430 "data/maps/LittlerootTown/scripts.pory"

# 431 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerFemale::
# 432 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterLeft
# 433 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 434 "data/maps/LittlerootTown/scripts.pory"
	return
# 435 "data/maps/LittlerootTown/scripts.pory"

# 436 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale::
# 437 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 438 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 439 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerMale2
# 440 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerMale3
# 441 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerMale4
# 442 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerMale5
# 443 "data/maps/LittlerootTown/scripts.pory"
	return
# 444 "data/maps/LittlerootTown/scripts.pory"

# 445 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale::
# 446 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 447 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 448 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerFemale2
# 449 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerFemale3
# 450 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerFemale4
# 451 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerFemale5
# 452 "data/maps/LittlerootTown/scripts.pory"
	return
# 453 "data/maps/LittlerootTown/scripts.pory"

# 454 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer0::
# 455 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 456 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 457 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer0
# 458 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 459 "data/maps/LittlerootTown/scripts.pory"
	return
# 460 "data/maps/LittlerootTown/scripts.pory"

# 461 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer1::
# 462 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 463 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 464 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer1
# 465 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 466 "data/maps/LittlerootTown/scripts.pory"
	return
# 467 "data/maps/LittlerootTown/scripts.pory"

# 468 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale2::
# 469 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 470 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 471 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
# 472 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 473 "data/maps/LittlerootTown/scripts.pory"
	return
# 474 "data/maps/LittlerootTown/scripts.pory"

# 475 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale3::
# 476 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 477 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 478 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
# 479 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 480 "data/maps/LittlerootTown/scripts.pory"
	return
# 481 "data/maps/LittlerootTown/scripts.pory"

# 482 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale4::
# 483 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 484 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 485 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
# 486 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 487 "data/maps/LittlerootTown/scripts.pory"
	return
# 488 "data/maps/LittlerootTown/scripts.pory"

# 489 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale5::
# 490 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 491 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 492 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
# 493 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 494 "data/maps/LittlerootTown/scripts.pory"
	return
# 495 "data/maps/LittlerootTown/scripts.pory"

# 496 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale2::
# 497 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 498 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 499 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
# 500 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 501 "data/maps/LittlerootTown/scripts.pory"
	return
# 502 "data/maps/LittlerootTown/scripts.pory"

# 503 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale3::
# 504 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 505 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 506 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
# 507 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 508 "data/maps/LittlerootTown/scripts.pory"
	return
# 509 "data/maps/LittlerootTown/scripts.pory"

# 510 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale4::
# 511 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 512 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 513 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
# 514 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 515 "data/maps/LittlerootTown/scripts.pory"
	return
# 516 "data/maps/LittlerootTown/scripts.pory"

# 517 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale5::
# 518 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 519 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 520 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
# 521 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 522 "data/maps/LittlerootTown/scripts.pory"
	return
# 523 "data/maps/LittlerootTown/scripts.pory"

# 524 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale::
# 525 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 526 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 527 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeMale2
# 528 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeMale3
# 529 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeMale4
# 530 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeMale5
# 531 "data/maps/LittlerootTown/scripts.pory"
	return
# 532 "data/maps/LittlerootTown/scripts.pory"

# 533 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale::
# 534 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 535 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 536 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeFemale2
# 537 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeFemale3
# 538 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeFemale4
# 539 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeFemale5
# 540 "data/maps/LittlerootTown/scripts.pory"
	return
# 541 "data/maps/LittlerootTown/scripts.pory"

# 542 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome0::
# 543 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome0
# 544 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 545 "data/maps/LittlerootTown/scripts.pory"
	return
# 546 "data/maps/LittlerootTown/scripts.pory"

# 547 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome1::
# 548 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome1
# 549 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 550 "data/maps/LittlerootTown/scripts.pory"
	return
# 551 "data/maps/LittlerootTown/scripts.pory"

# 552 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale2::
# 553 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale2
# 554 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 555 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 556 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 557 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 558 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 559 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 560 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 561 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 562 "data/maps/LittlerootTown/scripts.pory"
	return
# 563 "data/maps/LittlerootTown/scripts.pory"

# 564 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale3::
# 565 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale3
# 566 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 567 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 568 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 569 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 570 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 571 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 572 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 573 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 574 "data/maps/LittlerootTown/scripts.pory"
	return
# 575 "data/maps/LittlerootTown/scripts.pory"

# 576 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale4::
# 577 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale4
# 578 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 579 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 580 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 581 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 582 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 583 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 584 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 585 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 586 "data/maps/LittlerootTown/scripts.pory"
	return
# 587 "data/maps/LittlerootTown/scripts.pory"

# 588 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale5::
# 589 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale5
# 590 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 591 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 592 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 593 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 594 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 595 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 596 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 597 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 598 "data/maps/LittlerootTown/scripts.pory"
	return
# 599 "data/maps/LittlerootTown/scripts.pory"

# 600 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale2::
# 601 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
# 602 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 603 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 604 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 605 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 606 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 607 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 608 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 609 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 610 "data/maps/LittlerootTown/scripts.pory"
	return
# 611 "data/maps/LittlerootTown/scripts.pory"

# 612 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale3::
# 613 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
# 614 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 615 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 616 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 617 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 618 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 619 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 620 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 621 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 622 "data/maps/LittlerootTown/scripts.pory"
	return
# 623 "data/maps/LittlerootTown/scripts.pory"

# 624 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale4::
# 625 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
# 626 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 627 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 628 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 629 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 630 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 631 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 632 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 633 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 634 "data/maps/LittlerootTown/scripts.pory"
	return
# 635 "data/maps/LittlerootTown/scripts.pory"

# 636 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale5::
# 637 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
# 638 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 639 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 640 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 641 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 642 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 643 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 644 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 645 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 646 "data/maps/LittlerootTown/scripts.pory"
	return
# 647 "data/maps/LittlerootTown/scripts.pory"

# 648 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
# 649 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 650 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 651 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 652 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 653 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 654 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 655 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 656 "data/maps/LittlerootTown/scripts.pory"

# 657 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1:
# 658 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 659 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 660 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 661 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 662 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 663 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 664 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 665 "data/maps/LittlerootTown/scripts.pory"

# 666 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 667 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 668 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 669 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 670 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 671 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 672 "data/maps/LittlerootTown/scripts.pory"

# 673 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 674 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 675 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 676 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 677 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 678 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 679 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 680 "data/maps/LittlerootTown/scripts.pory"

# 681 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 682 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 683 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 684 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 685 "data/maps/LittlerootTown/scripts.pory"

# 686 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 687 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 688 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 689 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 690 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 691 "data/maps/LittlerootTown/scripts.pory"

# 692 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 693 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 694 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 695 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 696 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 697 "data/maps/LittlerootTown/scripts.pory"

# 698 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 699 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 700 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 701 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 702 "data/maps/LittlerootTown/scripts.pory"

# 703 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 704 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 705 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 706 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 707 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 708 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 709 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 710 "data/maps/LittlerootTown/scripts.pory"

# 711 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 712 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 713 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 714 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 715 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 716 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 717 "data/maps/LittlerootTown/scripts.pory"

# 718 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
# 719 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 720 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 721 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 722 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 723 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 724 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 725 "data/maps/LittlerootTown/scripts.pory"

# 726 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1:
# 727 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 728 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 729 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 730 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 731 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 732 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 733 "data/maps/LittlerootTown/scripts.pory"

# 734 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 735 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 736 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 737 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 738 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 739 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 740 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 741 "data/maps/LittlerootTown/scripts.pory"

# 742 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 743 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 744 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 745 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 746 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 747 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 748 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 749 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 750 "data/maps/LittlerootTown/scripts.pory"

# 751 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 752 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 753 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 754 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 755 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 756 "data/maps/LittlerootTown/scripts.pory"

# 757 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 758 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 759 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 760 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 761 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 762 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 763 "data/maps/LittlerootTown/scripts.pory"

# 764 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 765 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 766 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 767 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 768 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 769 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 770 "data/maps/LittlerootTown/scripts.pory"

# 771 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 772 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 773 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 774 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 775 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 776 "data/maps/LittlerootTown/scripts.pory"

# 777 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 778 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 779 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 780 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 781 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 782 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 783 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 784 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 785 "data/maps/LittlerootTown/scripts.pory"

# 786 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 787 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 788 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 789 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 790 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 791 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 792 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 793 "data/maps/LittlerootTown/scripts.pory"

# 794 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 795 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 796 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 797 "data/maps/LittlerootTown/scripts.pory"

# 798 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Mom::
# 799 "data/maps/LittlerootTown/scripts.pory"
	lock
# 800 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 801 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 802 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 803 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 804 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 805 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterUp
# 806 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 807 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 808 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 809 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 810 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 811 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 812 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 813 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 814 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 815 "data/maps/LittlerootTown/scripts.pory"
	end
# 816 "data/maps/LittlerootTown/scripts.pory"

# 817 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetReceivedRunningShoes::
# 818 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_MOM
# 819 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 820 "data/maps/LittlerootTown/scripts.pory"
    call killMom
# 821 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 822 "data/maps/LittlerootTown/scripts.pory"
	release
# 823 "data/maps/LittlerootTown/scripts.pory"
	end
# 824 "data/maps/LittlerootTown/scripts.pory"

# 825 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoes::
# 826 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 827 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 828 "data/maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 829 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 830 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 831 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
# 832 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 833 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 834 "data/maps/LittlerootTown/scripts.pory"
	delay 30
# 835 "data/maps/LittlerootTown/scripts.pory"
	return
# 836 "data/maps/LittlerootTown/scripts.pory"

# 837 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_OurNewHomeLetsGoInside:
# 838 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, we're here, honey!\p"
# 839 "data/maps/LittlerootTown/scripts.pory"
	.string "It must be tiring riding with our things\n"
# 840 "data/maps/LittlerootTown/scripts.pory"
	.string "in the moving truck.\p"
# 841 "data/maps/LittlerootTown/scripts.pory"
	.string "Well, this is LITTLEROOT TOWN.\p"
# 842 "data/maps/LittlerootTown/scripts.pory"
	.string "How do you like it?\n"
# 843 "data/maps/LittlerootTown/scripts.pory"
	.string "This is our new home!\p"
# 844 "data/maps/LittlerootTown/scripts.pory"
	.string "It has a quaint feel, but it seems to be\n"
# 845 "data/maps/LittlerootTown/scripts.pory"
	.string "an easy place to live, don't you think?\p"
# 846 "data/maps/LittlerootTown/scripts.pory"
	.string "And, you get your own room, {PLAYER}!\n"
# 847 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go inside.$"
# 848 "data/maps/LittlerootTown/scripts.pory"

# 849 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WaitPlayer:
# 850 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"
# 851 "data/maps/LittlerootTown/scripts.pory"

# 852 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WearTheseRunningShoes:
# 853 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
# 854 "data/maps/LittlerootTown/scripts.pory"
	.string "introduce yourself to PROF. BIRCH?\p"
# 855 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh! What an adorable POKéMON!\n"
# 856 "data/maps/LittlerootTown/scripts.pory"
	.string "You got it from PROF. BIRCH. How nice!\p"
# 857 "data/maps/LittlerootTown/scripts.pory"
	.string "You're your father's child, all right.\n"
# 858 "data/maps/LittlerootTown/scripts.pory"
	.string "You look good together with POKéMON!\p"
# 859 "data/maps/LittlerootTown/scripts.pory"
	.string "Here, honey! If you're going out on an\n"
# 860 "data/maps/LittlerootTown/scripts.pory"
	.string "adventure, wear these RUNNING SHOES.\p"
# 861 "data/maps/LittlerootTown/scripts.pory"
	.string "They'll put a zip in your step!$"
# 862 "data/maps/LittlerootTown/scripts.pory"

# 863 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_SwitchShoesWithRunningShoes:
# 864 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
# 865 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES.$"
# 866 "data/maps/LittlerootTown/scripts.pory"

# 867 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ExplainRunningShoes:
# 868 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
# 869 "data/maps/LittlerootTown/scripts.pory"
	.string "instructions.\p"
# 870 "data/maps/LittlerootTown/scripts.pory"
	.string "“Press the B Button while wearing these\n"
# 871 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES to run extra-fast!\p"
# 872 "data/maps/LittlerootTown/scripts.pory"
	.string "“Slip on these RUNNING SHOES and race\n"
# 873 "data/maps/LittlerootTown/scripts.pory"
	.string "in the great outdoors!”$"
# 874 "data/maps/LittlerootTown/scripts.pory"

# 875 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ComeHomeIfAnythingHappens:
# 876 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
# 877 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\p"
# 878 "data/maps/LittlerootTown/scripts.pory"
	.string "To think that you have your very own\n"
# 879 "data/maps/LittlerootTown/scripts.pory"
	.string "POKéMON now…\l"
# 880 "data/maps/LittlerootTown/scripts.pory"
	.string "Your father will be overjoyed.\p"
# 881 "data/maps/LittlerootTown/scripts.pory"
	.string "…But please be careful.\n"
# 882 "data/maps/LittlerootTown/scripts.pory"
	.string "If anything happens, you can come home.\p"
# 883 "data/maps/LittlerootTown/scripts.pory"
	.string "Go on, go get them, honey!$"
# 884 "data/maps/LittlerootTown/scripts.pory"

# 885 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanUsePCToStoreItems:
# 886 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
# 887 "data/maps/LittlerootTown/scripts.pory"
	.string "and POKéMON.\p"
# 888 "data/maps/LittlerootTown/scripts.pory"
	.string "The power of science is staggering!$"
# 889 "data/maps/LittlerootTown/scripts.pory"

# 890 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSpendsDaysInLab:
# 891 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
# 892 "data/maps/LittlerootTown/scripts.pory"
	.string "studying, then he'll suddenly go out in\l"
# 893 "data/maps/LittlerootTown/scripts.pory"
	.string "the wild to do more research…\p"
# 894 "data/maps/LittlerootTown/scripts.pory"
	.string "When does PROF. BIRCH spend time\n"
# 895 "data/maps/LittlerootTown/scripts.pory"
	.string "at home?$"
# 896 "data/maps/LittlerootTown/scripts.pory"

# 897 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
# 898 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
# 899 "data/maps/LittlerootTown/scripts.pory"
	.string "If you go outside and go in the grass,\n"
# 900 "data/maps/LittlerootTown/scripts.pory"
	.string "wild POKéMON will jump out!$"
# 901 "data/maps/LittlerootTown/scripts.pory"

# 902 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_DangerousIfYouDontHavePokemon:
# 903 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
# 904 "data/maps/LittlerootTown/scripts.pory"
	.string "your own POKéMON.$"
# 905 "data/maps/LittlerootTown/scripts.pory"

# 906 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanYouGoSeeWhatsHappening:
# 907 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
# 908 "data/maps/LittlerootTown/scripts.pory"
	.string "There are scary POKéMON outside!\n"
# 909 "data/maps/LittlerootTown/scripts.pory"
	.string "I can hear their cries!\p"
# 910 "data/maps/LittlerootTown/scripts.pory"
	.string "I want to go see what's going on,\n"
# 911 "data/maps/LittlerootTown/scripts.pory"
	.string "but I don't have any POKéMON…\p"
# 912 "data/maps/LittlerootTown/scripts.pory"
	.string "Can you go see what's happening\n"
# 913 "data/maps/LittlerootTown/scripts.pory"
	.string "for me?$"
# 914 "data/maps/LittlerootTown/scripts.pory"

# 915 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_YouSavedBirch:
# 916 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
# 917 "data/maps/LittlerootTown/scripts.pory"
	.string "I'm so glad!$"
# 918 "data/maps/LittlerootTown/scripts.pory"

# 919 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_GoodLuckCatchingPokemon:
# 920 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
# 921 "data/maps/LittlerootTown/scripts.pory"
	.string "Good luck!$"
# 922 "data/maps/LittlerootTown/scripts.pory"

# 923 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_TownSign:
# 924 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
# 925 "data/maps/LittlerootTown/scripts.pory"
	.string "“A town that can't be shaded any hue.”$"
# 926 "data/maps/LittlerootTown/scripts.pory"

# 927 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsLab:
# 928 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"
# 929 "data/maps/LittlerootTown/scripts.pory"

# 930 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_PlayersHouse:
# 931 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER}'s HOUSE$"
# 932 "data/maps/LittlerootTown/scripts.pory"

# 933 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsHouse:
# 934 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S HOUSE$"
# 935 "data/maps/LittlerootTown/scripts.pory"

# 936 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSomethingToShowYouAtLab:
# 937 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
# 938 "data/maps/LittlerootTown/scripts.pory"
	.string "That was good work out there!\p"
# 939 "data/maps/LittlerootTown/scripts.pory"
	.string "I knew there was something special\n"
# 940 "data/maps/LittlerootTown/scripts.pory"
	.string "about you when I first saw you,\l"
# 941 "data/maps/LittlerootTown/scripts.pory"
	.string "but I never expected this.\p"
# 942 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh, yes. Do you still have the POKéDEX\n"
# 943 "data/maps/LittlerootTown/scripts.pory"
	.string "I gave you?\p"
# 944 "data/maps/LittlerootTown/scripts.pory"
	.string "I have something to show you.\n"
# 945 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go to my LAB.$"

LittlerootTown_EventScript_GoInsideWithMom_Text_0:
# 80 "data/maps/LittlerootTown/scripts.pory"
	.string "Something feels... different.$"

killMom_Text_0:
# 174 "data/maps/LittlerootTown/scripts.pory"
	.string "Well, I guess I can begin my adventure as normal now...$"
