# Uncomment the next line to define a global platform for your project
 platform :ios, '15.0'

target 'AppflowExample' do
  # Comment the next line if you don't want to use dynamic frameworks
  use_frameworks!

  # Pods for AppflowExample
  pod 'PLCrashReporter'
  pod 'FMDB'
  pod 'Founq_KeychainIDFA'
  pod "gRPC-ProtoRPC"
  pod "Protobuf"

  # Attribution
  pod 'AppsFlyerFramework'
  pod 'Adjust'
  pod 'Branch'
  pod 'FBSDKCoreKit'
  
end


post_install do |installer|
  xcode_base_version = `xcodebuild -version | grep 'Xcode' | awk '{print $2}' | cut -d . -f 1`

  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      # Set C++17 for all pods (required by abseil and gRPC 1.76+)
      config.build_settings['CLANG_CXX_LANGUAGE_STANDARD'] = 'c++17'
      config.build_settings['CLANG_CXX_LIBRARY'] = 'libc++'

      # For xcode 15+ only
      if config.base_configuration_reference && Integer(xcode_base_version) >= 15
        xcconfig_path = config.base_configuration_reference.real_path
        xcconfig = File.read(xcconfig_path)
        xcconfig_mod = xcconfig.gsub(/DT_TOOLCHAIN_DIR/, "TOOLCHAIN_DIR")
        File.open(xcconfig_path, "w") { |file| file << xcconfig_mod }
      end

      # Fix BoringSSL-GRPC compilation issue for Xcode 16+
      if target.name == 'BoringSSL-GRPC'
        config.build_settings.delete('GCC_WARN_INHIBIT_ALL_WARNINGS')
        config.build_settings['GCC_PREPROCESSOR_DEFINITIONS'] ||= ['$(inherited)']
        config.build_settings['GCC_PREPROCESSOR_DEFINITIONS'] << 'OPENSSL_NO_ASM=1'
        # Remove problematic compiler flags
        if config.build_settings['OTHER_CFLAGS']
          config.build_settings['OTHER_CFLAGS'].delete('-GCC_WARN_INHIBIT_ALL_WARNINGS')
          config.build_settings['OTHER_CFLAGS'].delete('-G')
        end
      end
    end
  end
  
  installer.generated_projects.each do |project|
        project.targets.each do |target|
            target.build_configurations.each do |config|
                config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '15.0'
             end
        end
  end
end

