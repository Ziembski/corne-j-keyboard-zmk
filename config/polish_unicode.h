/*
 * Polish diacritic Unicode macros for ZMK
 *
 * Supports three OS input methods — uncomment ONE:
 *
 *   #define PL_UNICODE_LINUX    (Ctrl+Shift+U → hex → Enter)
 *   #define PL_UNICODE_WINDOWS  (Alt+numpad, requires registry tweak)
 *   #define PL_UNICODE_MACOS    (Unicode Hex Input method)
 *
 * Default: Linux (most common for ZMK users).
 *
 * Usage:
 *   #include "polish_unicode.h"
 *
 *   / {
 *       PL_UNICODE_MACROS
 *
 *       keymap {
 *           polish_layer {
 *               bindings = <
 *                   &pl_a  &pl_c  &pl_e  &pl_l  &pl_n
 *                   &pl_o  &pl_s  &pl_x  &pl_z
 *               >;
 *           };
 *       };
 *   };
 */

#pragma once

#include <dt-bindings/zmk/keys.h>
#include <behaviors.dtsi>

/* ── OS selection ─────────────────────────────────────────────────────────── */
#define PL_UNICODE_LINUX
/* #define PL_UNICODE_WINDOWS */
/* #define PL_UNICODE_MACOS */

/* ── Timing (ms) ──────────────────────────────────────────────────────────── */
#define PL_TAP_MS   15
#define PL_WAIT_MS  10

/* ── Per-OS wrappers ──────────────────────────────────────────────────────── */

#ifdef PL_UNICODE_LINUX
/*
 * Linux: Ctrl+Shift+U, type hex digits, then Enter.
 * GTK apps (GNOME, etc.) accept this natively.
 * For terminal/X11 apps set GTK_IM_MODULE='' if needed.
 */
#define UC_START  &macro_press &kp LCTRL &kp LSHFT  \
                  &macro_tap   &kp U                 \
                  &macro_release &kp LCTRL &kp LSHFT
#define UC_END    &macro_tap &kp RET
#endif

#ifdef PL_UNICODE_WINDOWS
/*
 * Windows: hold Alt, type +XXXX on numpad.
 * Requires EnableHexNumpad registry entry:
 *   HKCU\Control Panel\Input Method → EnableHexNumpad = "1"
 */
#define UC_START  &macro_press &kp LALT \
                  &macro_tap   &kp KP_PLUS
#define UC_END    &macro_release &kp LALT
#endif

#ifdef PL_UNICODE_MACOS
/*
 * macOS: hold Alt, type hex code.
 * Requires "Unicode Hex Input" keyboard selected in System Settings.
 */
#define UC_START  &macro_press &kp LALT
#define UC_END    &macro_release &kp LALT
#endif

/* ── Hex digit helpers ────────────────────────────────────────────────────── */
#define HEX0  &kp N0
#define HEX1  &kp N1
#define HEX2  &kp N2
#define HEX3  &kp N3
#define HEX4  &kp N4
#define HEX5  &kp N5
#define HEX6  &kp N6
#define HEX7  &kp N7
#define HEX8  &kp N8
#define HEX9  &kp N9
#define HEXA  &kp A
#define HEXB  &kp B
#define HEXC  &kp C
#define HEXD  &kp D
#define HEXE  &kp E
#define HEXF  &kp F

/*
 * ── Macro body builder ────────────────────────────────────────────────────
 *
 * PL_UC_4(a,b,c,d)  →  four hex digits for U+0xxx codes  (ą ć ę ł ń ś ź ż)
 * PL_UC_3(a,b,c)    →  three hex digits for U+00xx codes  (ó Ó)
 *
 * Each macro: press modifier → tap digits → release / confirm
 */
#define PL_UC_4(a,b,c,d) \
    UC_START              \
    &macro_tap a b c d    \
    UC_END

#define PL_UC_3(a,b,c)  \
    UC_START             \
    &macro_tap a b c     \
    UC_END

/* ── Macro definitions ────────────────────────────────────────────────────── */
/*
 * Char │ Codepoint │  Hex digits
 * ─────┼───────────┼────────────
 *  ą   │  U+0105   │  0 1 0 5
 *  Ą   │  U+0104   │  0 1 0 4
 *  ć   │  U+0107   │  0 1 0 7
 *  Ć   │  U+0106   │  0 1 0 6
 *  ę   │  U+0119   │  0 1 1 9
 *  Ę   │  U+0118   │  0 1 1 8
 *  ł   │  U+0142   │  0 1 4 2
 *  Ł   │  U+0141   │  0 1 4 1
 *  ń   │  U+0144   │  0 1 4 4
 *  Ń   │  U+0143   │  0 1 4 3
 *  ó   │  U+00F3   │  0 0 F 3
 *  Ó   │  U+00D3   │  0 0 D 3
 *  ś   │  U+015B   │  0 1 5 B
 *  Ś   │  U+015A   │  0 1 5 A
 *  ź   │  U+017A   │  0 1 7 A
 *  Ź   │  U+0179   │  0 1 7 9
 *  ż   │  U+017C   │  0 1 7 C
 *  Ż   │  U+017B   │  0 1 7 B
 */

#define PL_UNICODE_MACROS \
\
    pl_a: pl_a {                                                        \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX0, HEX5) >;               \
        /* ą  U+0105 */                                                 \
    };                                                                  \
\
    pl_ca: pl_ca {                                                      \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX0, HEX4) >;               \
        /* Ą  U+0104 */                                                 \
    };                                                                  \
\
    pl_c: pl_c {                                                        \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX0, HEX7) >;               \
        /* ć  U+0107 */                                                 \
    };                                                                  \
\
    pl_cc: pl_cc {                                                      \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX0, HEX6) >;               \
        /* Ć  U+0106 */                                                 \
    };                                                                  \
\
    pl_e: pl_e {                                                        \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX1, HEX9) >;               \
        /* ę  U+0119 */                                                 \
    };                                                                  \
\
    pl_ce: pl_ce {                                                      \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX1, HEX8) >;               \
        /* Ę  U+0118 */                                                 \
    };                                                                  \
\
    pl_l: pl_l {                                                        \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX4, HEX2) >;               \
        /* ł  U+0142 */                                                 \
    };                                                                  \
\
    pl_cl: pl_cl {                                                      \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX4, HEX1) >;               \
        /* Ł  U+0141 */                                                 \
    };                                                                  \
\
    pl_n: pl_n {                                                        \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX4, HEX4) >;               \
        /* ń  U+0144 */                                                 \
    };                                                                  \
\
    pl_cn: pl_cn {                                                      \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX4, HEX3) >;               \
        /* Ń  U+0143 */                                                 \
    };                                                                  \
\
    pl_o: pl_o {                                                        \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX0, HEXF, HEX3) >;               \
        /* ó  U+00F3 */                                                 \
    };                                                                  \
\
    pl_co: pl_co {                                                      \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX0, HEXD, HEX3) >;               \
        /* Ó  U+00D3 */                                                 \
    };                                                                  \
\
    pl_s: pl_s {                                                        \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX5, HEXB) >;               \
        /* ś  U+015B */                                                 \
    };                                                                  \
\
    pl_cs: pl_cs {                                                      \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX5, HEXA) >;               \
        /* Ś  U+015A */                                                 \
    };                                                                  \
\
    pl_x: pl_x {                                                        \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX7, HEXA) >;               \
        /* ź  U+017A */                                                 \
    };                                                                  \
\
    pl_cx: pl_cx {                                                      \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX7, HEX9) >;               \
        /* Ź  U+0179 */                                                 \
    };                                                                  \
\
    pl_z: pl_z {                                                        \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX7, HEXC) >;               \
        /* ż  U+017C */                                                 \
    };                                                                  \
\
    pl_cz: pl_cz {                                                      \
        compatible = "zmk,behavior-macro";                              \
        #binding-cells = <0>;                                           \
        tap-ms = <PL_TAP_MS>;                                           \
        wait-ms = <PL_WAIT_MS>;                                         \
        bindings = < PL_UC_4(HEX0, HEX1, HEX7, HEXB) >;               \
        /* Ż  U+017B */                                                 \
    };

/*
 * ── Full keymap example ───────────────────────────────────────────────────
 *
 * / {
 *     behaviors {
 *         PL_UNICODE_MACROS
 *     };
 *
 *     keymap {
 *         compatible = "zmk,keymap";
 *
 *         default_layer {
 *             bindings = < ... >;
 *         };
 *
 *         polish_layer {
 *             bindings = <
 *                 // lowercase row
 *                 &pl_a  &pl_c  &pl_e  &pl_l  &pl_n
 *                 &pl_o  &pl_s  &pl_x  &pl_z
 *                 // uppercase row
 *                 &pl_ca &pl_cc &pl_ce &pl_cl &pl_cn
 *                 &pl_co &pl_cs &pl_cx &pl_cz
 *             >;
 *         };
 *     };
 * };
 */
