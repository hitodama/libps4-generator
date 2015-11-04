/* SCE headers to be included */

#include <libc_internal.h>

#include <kernel.h>	// as [libkernel.sprx]
#noinclude <rt.h>	// as [librt.sprx]
#noinclude <ulobjmgr.h>	// as [ulobjmgr.sprx]

#noinclude <mono_compiler_bridge.h>	// as [libMonoCompilerBridge.sprx]
#noinclude <mono_compiler.h>	// as [libMonoCompiler.sprx]
#noinclude <mono_virtual_machine_bridge.h>	// as [libMonoVirtualMachineBridge.sprx]
#noinclude <mono_virtual_machine.h>	// as [libMonoVirtualMachine.sprx]

/*
	Don't remove "as" comments above as they are used in the module lookup ;)
	Sadly these modules don't follow the exact naming scheme as the others.
	The syntax for it is module_header.h\t// as [moduleName]
*/

#include <sysmodule.h>

#noinclude <fios2.h>
#include <net.h>
#noinclude <ipmi.h>
#noinclude <mbus.h>
#noinclude <reg_mgr.h>
#noinclude <rtc.h>
#noinclude <av_setting.h>
#noinclude <video_out.h>
#noinclude <gnm_driver.h>
#noinclude <audio_out.h>
#noinclude <audio_in.h>
#noinclude <ajm.h>
#include <pad.h>
#noinclude <dbg.h>
#noinclude <net_ctl.h>
#noinclude <http.h>
#noinclude <ssl.h>
#noinclude <np_common.h>
#noinclude <np_manager.h>
#noinclude <np_web_api.h>
#noinclude <save_data.h>
#noinclude <system_service.h>
#noinclude <user_service.h>
#noinclude <common_dialog.h>
#noinclude <sys_util.h>
#noinclude <perf.h>
#include <camera.h>
#noinclude <web_kit2_for_video_service.h>
#noinclude <orbis_compat_for_video_service.h>
#noinclude <disc_map.h>
#noinclude <fiber.h>
#noinclude <ult.h>
#noinclude <ngs2.h>
#noinclude <xml.h>
#noinclude <np_utility.h>
#noinclude <voice.h>
#noinclude <np_matching2.h>
#noinclude <np_score_ranking.h>
#noinclude <rudp.h>
#noinclude <np_tus.h>
#noinclude <face.h>
#noinclude <smart.h>
#noinclude <json.h>
#noinclude <game_live_streaming.h>
#noinclude <companion_util.h>
#noinclude <play_go.h>
#noinclude <font.h>
#noinclude <video_recording.h>
#noinclude <audiodec.h>
#noinclude <jpeg_dec.h>
#noinclude <jpeg_enc.h>
#noinclude <png_dec.h>
#noinclude <png_enc.h>
#noinclude <videodec.h>
#noinclude <move.h>
#noinclude <pad_tracker.h>
#noinclude <depth.h>
#noinclude <hand.h>
#noinclude <ime.h>
#noinclude <ime_dialog.h>
#noinclude <vdec_core.h>
#noinclude <np_party.h>
#noinclude <avcap.h>
#noinclude <font_ft.h>
#noinclude <free_type_ot.h>
#noinclude <free_type_ol.h>
#noinclude <free_type_opt_ol.h>
#noinclude <screen_shot.h>
#noinclude <np_auth.h>
#noinclude <voice_qos.h>
#noinclude <sys_core.h>
#noinclude <m4aac_enc.h>
#noinclude <audiodec_cpu.h>
#noinclude <cdlg_util_server.h>
#noinclude <sulpha.h>
#noinclude <save_data_dialog.h>
#noinclude <invitation_dialog.h>
#noinclude <keyboard.h>
#noinclude <msg_dialog.h>
#noinclude <av_player.h>
#noinclude <content_export.h>
#noinclude <vision_manager.h>
#noinclude <ac3_enc.h>
#noinclude <app_inst_util.h>
#noinclude <venc_core.h>
#noinclude <audio3d.h>
#noinclude <np_commerce.h>
#noinclude <hid_control.h>
#noinclude <mouse.h>
#noinclude <companion_httpd.h>
#noinclude <web_browser_dialog.h>
#noinclude <error_dialog.h>
#noinclude <np_trophy.h>
#noinclude <video_core_interface.h>
#noinclude <video_core_server_interface.h>
#noinclude <np_sns.h>
#noinclude <np_sns_facebook_dialog.h>
#noinclude <move_tracker.h>
#noinclude <np_profile_dialog.h>
#noinclude <np_friend_list_dialog.h>
#noinclude <app_content.h>
#noinclude <marlin.h>
#noinclude <dts_enc.h>
#noinclude <np_signaling.h>
#noinclude <remote_play.h>
#noinclude <usbd.h>
#noinclude <game_custom_data_dialog.h>
#noinclude <np_eula_dialog.h>
#noinclude <random.h>
#noinclude <dipsw.h>
#noinclude <s3_d_conversion.h>
#noinclude <ottv_capture.h>
#noinclude <bgft.h>
#noinclude <audiodec_cpu_ddp.h>
#noinclude <audiodec_cpu_m4aac.h>
#noinclude <audiodec_cpu_dts.h>
#noinclude <audiodec_cpu_dts_hd_lbr.h>
#noinclude <audiodec_cpu_dts_hd_ma.h>
#noinclude <audiodec_cpu_lpcm.h>
#noinclude <bemp2sys.h>
#noinclude <beisobmf.h>
#noinclude <play_ready.h>
#noinclude <video_native_ext_essential.h>
#noinclude <zlib.h>
#noinclude <idu_util.h>
#noinclude <psm.h>
#noinclude <dtcp_ip.h>
#noinclude <kb_emulate.h>
#noinclude <app_checker.h>
#noinclude <np_grief_report.h>
#noinclude <content_search.h>
#noinclude <share_utility.h>
#noinclude <web.h>
#noinclude <web_kit2.h>
#noinclude <deci4h.h>
#noinclude <head_tracker.h>
#noinclude <game_update.h>
#noinclude <auto_mounter_client.h>
#noinclude <system_gesture.h>
#noinclude <vdec_savc.h>
#noinclude <vdec_savc2.h>
#noinclude <videodec2.h>
#noinclude <vdecwrap.h>
#noinclude <convert_keycode.h>

#noinclude <abstract_local.h>
#noinclude <abstract_storage.h>
#noinclude <abstract_twitter.h>
#noinclude <composite_ext.h>
#noinclude <gv_mp4_parser.h>
#noinclude <jit_bridge.h>
#noinclude <jpeg_parser.h>
#noinclude <jsc_compiler.h>
#noinclude <manx_wtf.h>
#noinclude <metadata_reader_writer.h>
#noinclude <music_core_server_client_js_ex.h>
#noinclude <orbis_compat.h>
/*needs to be _v_s_h otherwise case sensitive again*/
#noinclude <pigletv2_v_s_h.h>

#crashinclude <vsh_common_aot.h>

/*not found*/
//trlp
//dbg_keyboard
//injected_bundle
//music_core_server_client
//play_go_dev
//razor_gpu_thread_trace
//shacc_v_s_h
//update_service
//vsh_aot

/* _anything else (headers.h) is resolved against libSceLibcInternal and libkernel */
