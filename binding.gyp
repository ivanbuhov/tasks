{
    "variables": {},
    "includes": [],
    "targets": [
        {
            "target_name": "tasks_addon",
            "type": "<(library)",
            "dependencies": [ "tasks_lib", "<!(node -p \"require('node-addon-api').gyp\")" ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")",
                "src/addon"
            ],
            "sources": [
                "src/addon/addon.cpp"
            ]
        },
        {
            "target_name": "tasks_lib",
            "type": "static_library",
            "include_dirs": [
                "src/tasks/include"
            ],
            "direct_dependent_settings": {
                "include_dirs": [
                    "src/tasks/include"
                ]
            },
            "sources": [
                "src/tasks/task.cpp",
                "src/tasks/tasks_list.cpp"
            ]
        }
        ],
    "conditions": []
}