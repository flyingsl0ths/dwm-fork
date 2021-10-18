/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 3;   /* border pixel of windows */
static const int corner_radius           = 0;
static const unsigned int snap           = 32;  /* snap pixel */
static const unsigned int gappih         = 20;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 30;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 0;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int focusonwheel            = 0;
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = -1;
static const unsigned int systrayspacing = 0;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */
/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_BOTTOM_BAR_SLIM;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[]               = {"JetBrainsMonoMedium Nerd Font:size=13:antialias=true" };
static const char dmenufont[]            = "JetBrainsMonoMedium Nerd Font:size=13:antialias=true";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#F8F8F2";
static char normbgcolor[]                = "#282A36";
static char normbordercolor[]            = "#44475A";
static char normfloatcolor[]             = "#BD93F9";

static char selfgcolor[]                 = "#44475A";
static char selbgcolor[]                 = "#8BE9FD";
static char selbordercolor[]             = "#8BE9FD";
static char selfloatcolor[]              = "#8BE9FD";

static char titlenormfgcolor[]           = "#F8F8F2";
static char titlenormbgcolor[]           = "#282A36";
static char titlenormbordercolor[]       = "#44475A";
static char titlenormfloatcolor[]        = "#BD93F9";

static char titleselfgcolor[]            = "#44475A";
static char titleselbgcolor[]            = "#8BE9FD";
static char titleselbordercolor[]        = "#8BE9FD";
static char titleselfloatcolor[]         = "#8BE9FD";

static char tagsnormfgcolor[]            = "#F8F8F2";
static char tagsnormbgcolor[]            = "#282A36";
static char tagsnormbordercolor[]        = "#44475A";
static char tagsnormfloatcolor[]         = "#BD93F9";

static char tagsselfgcolor[]             = "#44475A";
static char tagsselbgcolor[]             = "#8BE9FD";
static char tagsselbordercolor[]         = "#8BE9FD";
static char tagsselfloatcolor[]          = "#8BE9FD";

static char hidnormfgcolor[]             = "#8BE9FD";
static char hidselfgcolor[]              = "#6272A4";
static char hidnormbgcolor[]             = "#282A36";
static char hidselbgcolor[]              = "#282A36";

static char urgfgcolor[]                 = "#F8F8F2";
static char urgbgcolor[]                 = "#282A36";
static char urgbordercolor[]             = "#FF5555";
static char urgfloatcolor[]              = "#BD93F9";

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] = {
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                drawfunc                clickfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,              draw_tags,              click_tags,              "tags" },
	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,           draw_systray,           click_systray,           "systray" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,          draw_status2d,          click_status2d,          "status2d" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,          draw_wintitle,          click_wintitle,          "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int decorhints  = 1;    /* 1 means respect decoration hints */



static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "|M|",      centeredmaster },
	{ "(@)",      spiral },
	{ "HHH",      grid },
	{ NULL,       NULL },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/bash", "-c", cmd, NULL } }

/* helper for spawning no argument commands in the pre dwm-5.0 fashion */
#define SCMD(cmd) { .v = (const char*[]){ cmd, NULL } }

/* startup commands */
static const char *const autostart[] = {
	"xinput", "set-prop", "12", "316", "1",                                                           NULL,
	"gammy", "&",                                                                                     NULL,
	"dunst", "&",                                                                                     NULL,
	"nm-applet", "&",                                                                                 NULL,
    "lxpolkit", "&",                                                                                  NULL, 
    "/bin/bash", "-c", "(nohup picom &)",                                                             NULL,
    "/home/flyingsl0ths/.dwm/status_bar.sh", "&",                                                     NULL,
    "xwallpaper", "--output", "eDP", "--stretch", "/home/flyingsl0ths/Pictures/wallpaper/matrix.png", NULL,
	NULL /* terminate */
};

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m",  dmenumon,
    "-p",  "λ",
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	topbar ? NULL : "-b",
	NULL
};
static const char *termcmd[]  = { "alacritty", NULL };



static Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_r,            spawn,                  {.v = dmenucmd } },
	{ MODKEY,                       XK_Return,       spawn,                  {.v = termcmd } },
	{ MODKEY,                       XK_w,            spawn,                  SCMD("firedragon") },
	{ MODKEY,                       XK_p,            spawn,                  SCMD("pcmanfm") },
	{ MODKEY,                       XK_z,            spawn,                  SCMD("zathura") },
	{ MODKEY,                       XK_u,            spawn,                  SCMD("corectrl") },
	{ MODKEY,                       XK_v,            spawn,                  SCMD("vscodium") },
	{ MODKEY,                       XK_g,            spawn,                  SCMD("gimp") },
	{ MODKEY,                       XK_e,            spawn,                  SCMD("/home/flyingsl0ths/.local/bin/editors") },
	{ MODKEY,                       XK_a,            spawn,                  {.v = (const char*[])
                                                                                 {"/home/flyingsl0ths/.local/bin/game_mode", 
                                                                                  "android-studio", NULL} } },
	{ MODKEY|ShiftMask,             XK_e,            spawn,                  SCMD("~/.local/bin/editors") },
	{ MODKEY|ShiftMask,             XK_t,            spawn,                  SCMD("xfce4-taskmanager") },
	{ MODKEY|ShiftMask,             XK_w,            spawn,                  {.v = (const char*[])
                                                                                 {"firedragon", "--private-window", NULL} } },
	{ MODKEY|ShiftMask,             XK_l,            spawn,                  {.v = (const char*[])
                                                                                 {"xdg-screensaver", "lock", NULL} } } ,
	{ MODKEY,                       XK_F6,           spawn,                  {.v = (const char*[])
                                                                                 {"pamixer", "-t", NULL}} },
	{ MODKEY,                       XK_F7,           spawn,                  {.v = (const char*[])
                                                                                 {"pamixer", "-d", "5", NULL} } },
	{ MODKEY,                       XK_F8,           spawn,                  {.v = (const char*[])
                                                                                 {"pamixer", "-i", "5", NULL} } },
	{ MODKEY,                       XK_F2,           spawn,                  {.v = (const char*[])
                                                                                 {"brightnessctl", "-q", "set", "5%-", NULL} } },
	{ MODKEY,                       XK_F3,           spawn,                  {.v = (const char*[])
                                                                                 {"brightnessctl", "-q", "set", "5%+", NULL} } },
	{ MODKEY,                       XK_j,            focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,            focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_bracketleft,  focusdir,               {.i = 0 } }, // left
	{ MODKEY,                       XK_bracketright, focusdir,               {.i = 1 } }, // right
	{ MODKEY,                       XK_equal,        focusdir,               {.i = 2 } }, // up
	{ MODKEY,                       XK_minus,        focusdir,               {.i = 3 } }, // down
	{ MODKEY,                       XK_i,            incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,            incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_h,            setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,            setmfact,               {.f = +0.05} },
	{ MODKEY,                       XK_q,            killclient,             {0} },
	{ MODKEY,                       XK_t,            setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,            setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,            setlayout,              {.v = &layouts[2]} },
	{ MODKEY,                       XK_b,            setlayout,              {.v = &layouts[3]} },
	{ MODKEY,                       XK_c,            setlayout,              {.v = &layouts[4]} },
    { MODKEY,                       XK_s,            setlayout,              {.v = &layouts[5]} },
    { MODKEY,                       XK_g,            setlayout,              {.v = &layouts[6]} },
	{ MODKEY,                       XK_space,        setlayout,              {0} },
	{ MODKEY,                       XK_period,       focusmon,               {.i = +1 } },
	{ MODKEY,                       XK_comma,        focusmon,               {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_q,            quit,                   {0} },
	{ MODKEY|ShiftMask,             XK_b,            togglebar,              {0} },
	{ MODKEY|ShiftMask,             XK_r,            self_restart,           {0} },
	{ MODKEY|ShiftMask,             XK_space,        togglefloating,         {0} },
	{ MODKEY|ShiftMask,             XK_0,            tag,                    {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_comma,        tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,       tagmon,                 {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_bracketleft,  viewtoleft,             {0} }, // note keybinding conflict with focusdir
	{ MODKEY|ShiftMask,             XK_bracketright, viewtoright,            {0} }, // note keybinding conflict with focusdir
	{ MODKEY|ShiftMask,             XK_braceleft,    tagtoleft,              {0} },
	{ MODKEY|ShiftMask,             XK_braceright,   tagtoright,             {0} },
	{ MODKEY|ShiftMask,             XK_F1,           tagall,                 {.v = "1"} },
	{ MODKEY|ShiftMask,             XK_F2,           tagall,                 {.v = "2"} },
	{ MODKEY|ShiftMask,             XK_F3,           tagall,                 {.v = "3"} },
	{ MODKEY|ShiftMask,             XK_F4,           tagall,                 {.v = "4"} },
	{ MODKEY|ShiftMask,             XK_F5,           tagall,                 {.v = "5"} },
	{ MODKEY|ShiftMask,             XK_F6,           tagall,                 {.v = "6"} },
	{ MODKEY|ShiftMask,             XK_F7,           tagall,                 {.v = "7"} },
	{ MODKEY|ShiftMask,             XK_F8,           tagall,                 {.v = "8"} },
	{ MODKEY|ShiftMask,             XK_F9,           tagall,                 {.v = "9"} },
	{ MODKEY|ShiftMask,             XK_k,            movestack,              {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,            movestack,              {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_z,            zoom,                   {0} },
	{ MODKEY|ControlMask,           XK_bracketleft,  tagandviewtoleft,       {0} },
	{ MODKEY|ControlMask,           XK_bracketright, tagandviewtoright,      {0} },
	{ MODKEY|ControlMask,           XK_space,        focusmaster,            {0} },
	{ MODKEY|ControlMask,           XK_d,            distributetags,         {0} },
	{ MODKEY|ControlMask,           XK_e,            aspectresize,           {.i = +24} },
	{ MODKEY|ControlMask,           XK_r,            aspectresize,           {.i = -24} },
	{ MODKEY|ControlMask,           XK_s,            moveresize,             {.v = "0x 25y 0w 0h" } },
	{ MODKEY|ControlMask,           XK_w,            moveresize,             {.v = "0x -25y 0w 0h" } },
	{ MODKEY|ControlMask,           XK_d,            moveresize,             {.v = "25x 0y 0w 0h" } },
	{ MODKEY|ControlMask,           XK_a,            moveresize,             {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ControlMask,           XK_j,            moveresize,             {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ControlMask,           XK_k,            moveresize,             {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ControlMask,           XK_l,            moveresize,             {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ControlMask,           XK_h,            moveresize,             {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_g,            incrgaps,               {.i = +1 } },
	{ MODKEY|ControlMask,           XK_i,            incrigaps,              {.i = +1 } },
	{ MODKEY|ControlMask,           XK_o,            incrogaps,              {.i = +1 } },
	{ MODKEY|ControlMask,           XK_n,            incrihgaps,             {.i = +1 } },
	{ MODKEY|ControlMask,           XK_m,            incrivgaps,             {.i = +1 } },
	{ MODKEY|ControlMask,           XK_comma,        incrohgaps,             {.i = +1 } },
	{ MODKEY|ControlMask,           XK_period,       incrovgaps,             {.i = +1 } },
	{ MODKEY|ControlMask,           XK_0,            togglegaps,             {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_g,            incrgaps,               {.i = -1 } },
	{ MODKEY|ControlMask|ShiftMask, XK_i,            incrigaps,              {.i = -1 } },
	{ MODKEY|ControlMask|ShiftMask, XK_o,            incrogaps,              {.i = -1 } },
	{ MODKEY|ControlMask|ShiftMask, XK_n,            incrihgaps,             {.i = -1 } },
	{ MODKEY|ControlMask|ShiftMask, XK_m,            incrivgaps,             {.i = -1 } },
	{ MODKEY|ControlMask|ShiftMask, XK_comma,        incrohgaps,             {.i = -1 } },
	{ MODKEY|ControlMask|ShiftMask, XK_period,       incrovgaps,             {.i = -1 } },
	{ MODKEY|ControlMask|ShiftMask, XK_0,            defaultgaps,            {0} },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};



