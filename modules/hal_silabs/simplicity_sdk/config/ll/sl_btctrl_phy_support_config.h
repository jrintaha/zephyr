/***************************************************************************//**
 * @brief Bluetooth Controller PHY configuration adaptation for Zephyr
 *******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/
#ifndef SL_BTCTRL_PHY_SUPPORT_CONFIG_H
#define SL_BTCTRL_PHY_SUPPORT_CONFIG_H

#if defined(CONFIG_BT_CTRL_PHY_2M)
#define SL_BT_CONTROLLER_2M_PHY_SUPPORT		1
#else
#define SL_BT_CONTROLLER_2M_PHY_SUPPORT		0
#endif

#if defined(CONFIG_BT_CTRL_PHY_CODED)
#define SL_BT_CONTROLLER_CODED_PHY_SUPPORT	1
#else
#define SL_BT_CONTROLLER_CODED_PHY_SUPPORT	0
#endif

#endif /* SL_BTCTRL_PHY_SUPPORT_CONFIG_H */
