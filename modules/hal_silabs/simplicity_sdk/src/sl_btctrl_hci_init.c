/***************************************************************************//**
 * @file
 * @brief Bluetooth HCI layer initialization for Silicon Labs EFR32
 *******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the
 * use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software in a
 *    product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#include <sl_btctrl_config.h>
#include <sl_hci_common_transport.h>
#include <zephyr/sys/util_macro.h>

void sl_bt_hci_init(void)
{
	sl_bthci_init_upper();
	sl_btctrl_hci_parser_init_default();

	IF_ENABLED(CONFIG_BT_SILABS_EFR32_HCI_VS, (sl_bthci_init_vs();))
	IF_ENABLED(CONFIG_BT_CONN, (sl_btctrl_hci_parser_init_conn();))
#if defined(SL_CATALOG_BLUETOOTH_FEATURE_ADVERTISER_PRESENT)
	sl_btctrl_hci_parser_init_adv();
#endif
#if defined(SL_CATALOG_BLUETOOTH_FEATURE_ADVERTISER_PAST_PRESENT)
	sl_btctrl_hci_parser_init_adv_past();
#endif
#if defined(SL_CATALOG_BLUETOOTH_FEATURE_ADVERTISER_PAST_PRESENT) \
	|| defined(SL_CATALOG_BLUETOOTH_FEATURE_SYNC_PAST_PRESENT) \
	|| defined(SL_CATALOG_BLUETOOTH_FEATURE_PAST_RECEIVER_PRESENT)
	sl_btctrl_hci_parser_init_past();
#endif
#if defined(SL_CATALOG_BLUETOOTH_FEATURE_CS_PRESENT) \
	|| defined(SL_CATALOG_BLUETOOTH_FEATURE_CS_TEST_PRESENT)
	sl_btctrl_hci_parser_init_cs();
#endif
	IF_ENABLED(CONFIG_BT_PHY_UPDATE, (sl_btctrl_hci_parser_init_phy();))
	IF_ENABLED(CONFIG_BT_CTLR_PRIVACY, (sl_btctrl_hci_parser_init_privacy();))
	IF_ENABLED(CONFIG_BT_CTLR_SUBRATING, (sl_btctrl_hci_parser_init_subrate();))
}
