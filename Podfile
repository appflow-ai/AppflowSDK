# Uncomment the next line to define a global platform for your project
# platform :ios, '9.0'

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
  installer.generated_projects.each do |project|
      project.targets.each do |target|
          target.build_configurations.each do |config|
              config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '13.0'
          end
      end
  end
  installer.pods_project.targets.each do |target|
    if target.name == 'BoringSSL-GRPC'
      target.source_build_phase.files.each do |file|
        if file.settings && file.settings['COMPILER_FLAGS']
          flags = file.settings['COMPILER_FLAGS'].split
          flags.reject! { |flag| flag == '-GCC_WARN_INHIBIT_ALL_WARNINGS' }
          file.settings['COMPILER_FLAGS'] = flags.join(' ')
        end
      end
    end
  end
end

