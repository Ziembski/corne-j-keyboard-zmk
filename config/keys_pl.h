// Copyright 2025 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once


#include <dt-bindings/zmk/hid_usage.h>
#include <dt-bindings/zmk/hid_usage_pages.h>
#include <dt-bindings/zmk/modifiers.h>
#include <dt-bindings/zmk/keys.h>

// Aliases


#define PL_E    E    // E
#define PL_O    O    // O
#define PL_A    A    // A
#define PL_S    S    // S
#define PL_L    L    // L
#define PL_Z    Z    // Z
#define PL_X    X    // X
#define PL_C    C    // C
#define PL_N    N    // N

#define PL_EOGO RA(PL_E)    // Ę
#define PL_EURO RA(PL_U)    // €
#define PL_OACU RA(PL_O)    // Ó
#define PL_AOGO RA(PL_A)    // Ą
#define PL_SACU RA(PL_S)    // Ś
#define PL_LSTR RA(PL_L)    // Ł
#define PL_ZDOT RA(PL_Z)    // Ż
#define PL_ZACU RA(PL_X)    // Ź
#define PL_CACU RA(PL_C)    // Ć
#define PL_NACU RA(PL_N)    // Ń

