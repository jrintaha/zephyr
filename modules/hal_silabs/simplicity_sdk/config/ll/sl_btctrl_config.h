/***************************************************************************//**
 * @brief Bluetooth Controller configuration adaptation for Zephyr
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
#ifndef SL_BTCTRL_CONFIG_H
#define SL_BTCTRL_CONFIG_H

/* The following section maps common Zephyr Bluetooth host Kconfig options
 * to SL_CATALOG items. Note that the feature dependencies are handled
 * indirectly via Kconfig dependency resolution.
 */
#if defined(CONFIG_BT_FILTER_ACCEPT_LIST)
#define SL_CATALOG_BLUETOOTH_FEATURE_ACCEPT_LIST_PRESENT
#endif

#if defined(CONFIG_BT_PER_ADV_SYNC_TRANSFER_SENDER)
#if defined(CONFIG_BT_PER_ADV)
#define SL_CATALOG_BLUETOOTH_FEATURE_ADVERTISER_PAST_PRESENT
#endif
#if defined(CONFIG_BT_PER_ADV_SYNC)
#define SL_CATALOG_BLUETOOTH_FEATURE_SYNC_PAST_PRESENT
#endif
#endif

#if defined(CONFIG_BT_BROADCASTER)
/* Both the legacy and extended advertiser require the base advertiser. */
#define SL_CATALOG_BLUETOOTH_FEATURE_ADVERTISER_PRESENT
#define SL_CATALOG_BLUETOOTH_FEATURE_LEGACY_ADVERTISER_PRESENT
#endif

#if defined(CONFIG_BT_ISO)
#define SL_CATALOG_BLUETOOTH_FEATURE_CIS_PRESENT
#endif

#if defined(CONFIG_BT_CONN)
#define SL_CATALOG_BLUETOOTH_FEATURE_CONNECTION_PRESENT
#endif

#if defined(CONFIG_BT_SUBRATING)
#define SL_CATALOG_BLUETOOTH_FEATURE_CONNECTION_SUBRATING_PRESENT
#endif

#if !defined(CONFIG_BT_PHY_UPDATE)
#define SL_CATALOG_BLUETOOTH_CONNECTION_PHY_UPDATE_INCOMPATIBLE_PRESENT
#endif

#if defined(CONFIG_BT_CHANNEL_SOUNDING)
#define SL_CATALOG_BLUETOOTH_FEATURE_CS_PRESENT
#endif

#if defined(CONFIG_BT_CHANNEL_SOUNDING_TEST)
#define SL_CATALOG_BLUETOOTH_FEATURE_CS_TEST_PRESENT
#endif

#if defined(CONFIG_BT_EXT_ADV)
#define SL_CATALOG_BLUETOOTH_FEATURE_EXTENDED_ADVERTISER_PRESENT
#endif

#if defined(CONFIG_BT_PER_ADV_SYNC_TRANSFER_RECEIVER)
#define SL_CATALOG_BLUETOOTH_FEATURE_PAST_RECEIVER_PRESENT
#endif

#if defined(CONFIG_BT_PER_ADV_RSP)
#define SL_CATALOG_BLUETOOTH_FEATURE_PAWR_ADVERTISER_PRESENT
#if defined(CONFIG_BT_CONN)
#define SL_CATALOG_BLUETOOTH_FEATURE_CONNECTION_PAWR_SCHEDULING_PRESENT
#endif
#endif

#if defined(CONFIG_BT_PER_ADV_SYNC_RSP)
#define SL_CATALOG_BLUETOOTH_FEATURE_PAWR_SYNC_PRESENT
#endif

#if defined(CONFIG_BT_PER_ADV)
#define SL_CATALOG_BLUETOOTH_FEATURE_PERIODIC_ADVERTISER_PRESENT
#endif

#if defined(CONFIG_BT_EXT_ADV_CODING_SELECTION)
/* This does not have any corresponding SL_CATALOG feature, as the coding selection
 * is implicitly supported depending on the 2M / Coded PHY support, when extended
 * advertising is enabled.
 */
#endif

#if defined(CONFIG_BT_TRANSMIT_POWER_CONTROL)
#define SL_CATALOG_BLUETOOTH_FEATURE_POWER_CONTROL_PRESENT
#endif

#if defined(CONFIG_BT_PRIVACY)
#define SL_CATALOG_BLUETOOTH_FEATURE_RESOLVING_LIST_PRESENT
#endif

#if defined(CONFIG_BT_OBSERVER)
#define SL_CATALOG_BLUETOOTH_FEATURE_SCANNER_PRESENT
#endif

#if defined(CONFIG_BT_PER_ADV_SYNC)
#define SL_CATALOG_BLUETOOTH_FEATURE_SYNC_PRESENT
#endif

#if defined(CONFIG_BT_CTRL_DTM_HCI)
#define SL_CATALOG_BLUETOOTH_FEATURE_HCI_TEST_COMMANDS_PRESENT
#endif

#define SL_CATALOG_BLUETOOTH_FEATURE_PHY_SUPPORT_CONFIG_PRESENT

/* The following maps vendor-specific features to SL_CATALOG items */
#if defined(CONFIG_BT_SILABS_EFR32_HIGH_POWER)
#define SL_CATALOG_BLUETOOTH_FEATURE_HIGH_POWER_PRESENT
#endif

#if defined(CONFIG_BT_SILABS_EFR32_HIGH_POWER_AFH)
#define SL_CATALOG_BLUETOOTH_FEATURE_AFH_PRESENT
#endif

#define SL_CATALOG_BLUETOOTH_RCP_PRESENT

/* The following features are not currently supported with Zephyr */
#undef SL_CATALOG_BLUETOOTH_FEATURE_AOA_RECEIVER_PRESENT
#undef SL_CATALOG_BLUETOOTH_FEATURE_AOA_TRANSMITTER_PRESENT
#undef SL_CATALOG_BLUETOOTH_FEATURE_AOD_RECEIVER_PRESENT
#undef SL_CATALOG_BLUETOOTH_FEATURE_AOD_TRANSMITTER_PRESENT
#undef SL_CATALOG_BLUETOOTH_FEATURE_CONNECTION_ANALYZER_PRESENT
#undef SL_CATALOG_BLUETOOTH_FEATURE_CONNECTION_STATISTICS_PRESENT
#undef SL_CATALOG_BLUETOOTH_FEATURE_EVEN_SCHEDULING_PRESENT
#undef SL_CATALOG_BLUETOOTH_FEATURE_HCI_DEBUG_PRESENT
#undef SL_CATALOG_BLUETOOTH_FEATURE_RADIO_WATCHDOG_PRESENT
#undef SL_CATALOG_BLUETOOTH_FEATURE_USER_POWER_CONTROL_PRESENT
#undef SL_CATALOG_KERNEL_PRESENT /* Only relevant in the SiSDK RTOS adaptation */
#undef SL_CATALOG_RAIL_UTIL_COEX_PRESENT
#undef SL_RAIL_LIB_MULTIPROTOCOL_SUPPORT

/* Maps the controller configuration options from Kconfig to Silabs defines */
#define SL_BT_CONTROLLER_BUFFER_MEMORY				\
	CONFIG_BT_SILABS_EFR32_BUFFER_MEMORY
#define SL_BT_CONTROLLER_LE_BUFFER_SIZE_MAX			\
	CONFIG_BT_BUF_ACL_TX_COUNT
#define SL_BT_CONTROLLER_USER_ADVERTISERS			\
	CONFIG_BT_SILABS_EFR32_USER_ADVERTISERS
#define SL_BT_CONTROLLER_COMPLETED_PACKETS_THRESHOLD		\
	CONFIG_BT_SILABS_EFR32_COMPLETED_PACKETS_THRESHOLD
#define SL_BT_CONTROLLER_COMPLETED_PACKETS_EVENTS_TIMEOUT	\
	CONFIG_BT_SILABS_EFR32_COMPLETED_PACKETS_TIMEOUT
#define SL_BT_CONFIG_MAX_QUEUED_ADV_REPORTS			\
	CONFIG_BT_SILABS_EFR32_MAX_QUEUED_ADV_REPORTS

#endif /* SL_BTCTRL_CONFIG_H */
